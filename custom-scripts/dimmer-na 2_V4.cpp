/*
{
  desc:"Диммер MimiSmart",
  tag:"item",
  selectArea:true,
  name:"Установить",
  vars:[
    {name:"RS485",type:"devices-list",required:true,filter:["com-port"],desc:"RS-485"},
    {name:"ID1",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER01",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 1",width:500},
    {name:"DIMMER02",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 2",width:500},
    {name:"DIMMER03",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 3",width:500},
    {name:"DIMMER04",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 4",width:500},
    {type:"comment", style:"color:red", text:"Настройки первого канала:"},
    {name:"LOW01",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 1",descWidth:350},
    {name:"MAX01",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 1",descWidth:350},
    {name:"DEF01",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 1",descWidth:350},
    {name:"LINE01",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT01",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки второго канала:"},
    {name:"LOW02",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 2",descWidth:350},
    {name:"MAX02",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 2",descWidth:350},
    {name:"DEF02",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 2",descWidth:350},
    {name:"LINE02",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT02",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки третьего канала:"},
    {name:"LOW03",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 3",descWidth:350},
    {name:"MAX03",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 3",descWidth:350},
    {name:"DEF03",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 3",descWidth:350},
    {name:"LINE03",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT03",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки четвертого канала:"},
    {name:"LOW04",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 4",descWidth:350},
    {name:"MAX04",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 4",descWidth:350},
    {name:"DEF04",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 4",descWidth:350},
    {name:"LINE04",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT04",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {name:"ID2",type:"number",required:true,defaultValue:1,min:0,max:255,desc:"ID диммера",descWidth:350},
    {name:"DIMMER05",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 5",width:500},
    {name:"DIMMER06",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 6",width:500},
    {name:"DIMMER07",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 7",width:500},
    {name:"DIMMER08",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер 8",width:500},
    {type:"comment", style:"color:red", text:"Настройки первого канала:"},
    {name:"LOW05",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 5",descWidth:350},
    {name:"MAX05",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 5",descWidth:350},
    {name:"DEF05",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 5",descWidth:350},
    {name:"LINE05",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT05",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки 6го канала:"},
    {name:"LOW06",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 6",descWidth:350},
    {name:"MAX06",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 6",descWidth:350},
    {name:"DEF06",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 6",descWidth:350},
    {name:"LINE06",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT06",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки 7го канала:"},
    {name:"LOW07",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 7",descWidth:350},
    {name:"MAX07",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 7",descWidth:350},
    {name:"DEF07",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 7",descWidth:350},
    {name:"LINE07",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT07",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
    {type:"comment", style:"color:red", text:"Настройки 8го канала:"},
    {name:"LOW08",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Минимум 8",descWidth:350},
    {name:"MAX08",type:"number",required:true,defaultValue:0,min:0,max:250,desc:"Максимум 8",descWidth:350},
    {name:"DEF08",type:"number",required:true,defaultValue:100,min:0,max:250,desc:"По умолчанию 8",descWidth:350},
    {name:"LINE08",type:"number",required:true,defaultValue:10,min:10,max:80,desc:"Нелинейность 10 - линейное",descWidth:350},
    {name:"PROTECT08",type:"number",required:true,defaultValue:2000,min:0,max:2150,desc:"Ток защиты в мА. 0 - нет защиты",descWidth:350},
  ]
}
*/

u8 stopcontrol=0;

void secondSetup(){
    u16 j1 = PROTECT05;
    u16 j2 = PROTECT06;
    u16 j3 = PROTECT07;
    u16 j4 = PROTECT08;
    u8 writeSetup[49]={
        ID2, 0x10, 0x00, 0x35, 0x00, 0x14, 0x28,//общие данные
        0x00, LOW05, 0x00, MAX05, 0x00, DEF05, 0x00, LINE05, //Диммер 1
        0x00, LOW06, 0x00, MAX06, 0x00, DEF06, 0x00, LINE06, //Диммер 2
        0x00, LOW07, 0x00, MAX07, 0x00, DEF07, 0x00, LINE07, //Диммер 3
        0x00, LOW08, 0x00, MAX08, 0x00, DEF08, 0x00, LINE08, //Диммер 4
        j1>>8, j1, j2>>8, j2, j3>>8, j3, j4>>8, j4, //Защита по току
        0xCC, 0x16 //CRC
    };
    setStatus(RS485, &writeSetup);
    srvError("Установка завершена!!!");
    stopcontrol=0; //Возвращаем управление
}

//Настройка
V-ID/V-ADDR{
    stopcontrol=1;
    srvError("Установка параметров, ничего не трогайте!!!");
    u16 j1 = PROTECT01;
    u16 j2 = PROTECT02;
    u16 j3 = PROTECT03;
    u16 j4 = PROTECT04;
    u8 writeSetup[49]={
        ID1, 0x10, 0x00, 0x35, 0x00, 0x14, 0x28,//общие данные
        0x00, LOW01, 0x00, MAX01, 0x00, DEF01, 0x00, LINE01, //Диммер 1
        0x00, LOW02, 0x00, MAX02, 0x00, DEF02, 0x00, LINE02, //Диммер 2
        0x00, LOW03, 0x00, MAX03, 0x00, DEF03, 0x00, LINE03, //Диммер 3
        0x00, LOW04, 0x00, MAX04, 0x00, DEF04, 0x00, LINE04, //Диммер 4
        j1>>8, j1, j2>>8, j2, j3>>8, j3, j4>>8, j4, //Защита по току
        0xCC, 0x16 //CRC
    };
    setStatus(RS485, &writeSetup);
    delayedCall(secondSetup, 1);
}


//Управление
u8 numberidset=0;

V-ID/ms:150
{
    if(!stopcontrol){
        if(numberidset==0){
        //Уставка диммеров
            u8 data[33]={ID1, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
            0x00, [DIMMER01.0]&1, 0x00, [DIMMER01.1], 0x00, 0x01, //12
            0x00, [DIMMER02.0]&1, 0x00, [DIMMER02.1], 0x00, 0x01, //18
            0x00, [DIMMER03.0]&1, 0x00, [DIMMER03.1], 0x00, 0x01, //24
            0x00, [DIMMER04.0]&1, 0x00, [DIMMER04.1], 0x00, 0x01, //30
            0xCC, 0x16}; //32
            setStatus(RS485, &data);
            ++numberidset;
            return;
        } else if(numberidset==1){
            u8 data[33]={ID2, 0x10, 0x00, 0x28, 0x00, 0x0C, 0x18, //6
            0x00, [DIMMER05.0]&1, 0x00, [DIMMER05.1], 0x00, 0x01, //12
            0x00, [DIMMER06.0]&1, 0x00, [DIMMER06.1], 0x00, 0x01, //18
            0x00, [DIMMER07.0]&1, 0x00, [DIMMER07.1], 0x00, 0x01, //24
            0x00, [DIMMER08.0]&1, 0x00, [DIMMER08.1], 0x00, 0x01, //30
            0xCC, 0x16}; //32
            setStatus(RS485, &data);
            --numberidset;
            return;
        }
    }
}

//Вывода в лог
void stat()
{
u8 res[100]="";
        u8 *st = opt;
        u8 i = 0;
        sprintf(res,"%d ",optl);
        for(i = 0; i < optl; ++i){
            sprintf(res+strlen(res), " %x", st[i]);
        }
        sprintf(res+strlen(res), "\10");
        srvError(&res);
}

V-ID/RS485
{
    //stat();
}