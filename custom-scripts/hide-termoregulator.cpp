/*
{
  desc:"Heating Modbus (AUTO + MANUAL)",
  tag:"import-script",
  target:"RS485",
  selectArea:true,
  addItems:[
        {tag:"item", id:"%TARGET%", name:"HEAT1", "sub-id":"%SUBID01%", "type":"thermostat", "t-min":"5", "t-delta":"35"}
  ],
  vars:[
        {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS485"},
        {name:"Heat01",type:"hidden",value:"%TARGET%:%SUBID01%"},
        {name:"Address1",type:"number",min:"1",max:"247",required:true,defaultValue:"1"}
  ]
}
*/


u8 NeedSend = 0;
u8 write = 0;

u8 writeFrame[8]={0};
u8 readFrame[8]={0x00,0x03,0x00,0x00,0x00,0x03,0,0};

const u16 ID [] = { ADDR2ID(Heat01) };
const u8 SID [] = { ADDR2SID(Heat01) };
const u8 Addr [] = { Address1 };

//--------------------------------
// CRC
u16 CRC16(u8 *buf, u8 len){
    u16 crc = 0xFFFF;
    for(u8 pos = 0; pos < len-2; pos++){
        crc ^= buf[pos];
        for(u8 i=0;i<8;i++){
            if(crc & 1){
                crc >>=1;
                crc ^= 0xA001;
            } else crc >>=1;
        }
    }
    return crc;
}

void stat(){
    u8 res[100]="";
    u8 *st = opt;
    if (optl == 7 && st[1] == 3) {
        srvMessage("%cКоррекция = %d", 1, st[4]);
    } else {
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
    }
}

//--------------------------------
// WRITE REGISTER
void writeReg(u8 addr, u16 reg, u16 val){

    writeFrame[0]=addr;
    writeFrame[1]=0x06;

    writeFrame[2]=reg>>8;
    writeFrame[3]=reg;

    writeFrame[4]=val>>8;
    writeFrame[5]=val;

    u16 crc = CRC16(writeFrame,8);
    writeFrame[6]=crc;
    writeFrame[7]=crc>>8;

    setStatus(RS485, &writeFrame);
}

//--------------------------------
// SEND
void send(){

    cancelDelayedCall(send);

    if(NeedSend){

        u8 state[5]={0};
        getStatus(Heat01, state);

        u8 power = state[0];
        u8 temp  = state[1];

        // 1. ON/OFF (регистр 0)
        writeReg(Addr[0], 0x0000, power);

        // 2. режим
        // AUTO = 0, MANUAL = 1
        u8 mode = (power==1 && temp>0) ? 0 : 1;

        delayedCallMs(writeReg, 150, Addr[0], 0x0002, mode);

        // 3. температура (только AUTO)
        if(mode==0){
            u16 t = temp * 10;
            delayedCallMs(writeReg, 300, Addr[0], 0x0001, t);
        }

        NeedSend = 0;
        write = 0;
    }
}

//--------------------------------
// UI CHANGE
V-ID/Heat01{

    if(senderId()!=exciterId()){
        write = 1;
        NeedSend = 1;
        cancelDelayedCall(send);
        delayedCall(send,1);
    }
}

//--------------------------------
// POLLING
V-ID/s:3{

    if(write==0){

        readFrame[0]=Addr[0];

        u16 crc = CRC16(readFrame,8);
        readFrame[6]=crc;
        readFrame[7]=crc>>8;

        setStatus(RS485, &readFrame);
    }
}

//--------------------------------
// RECEIVE
V-ID/RS485{

    #ifdef DEBUG stat(); #endif

    if(optl>=11 && opt(1)==0x03){

        u8 state[5]={0};

        // ON/OFF
        state[0]=opt(3);

        // TEMP
        u16 t = (opt(5)<<8)|opt(6);
        state[1]=t/10;

        // MODE
        u8 mode = opt(7);

        if(mode==0) state[0]=65; // AUTO
        else state[0]=1; // MANUAL

        setStatus(@ID[0]:@SID[0], &state);
    }
}