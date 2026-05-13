/*
{
    desc:"Бассейн (типа штора)",
    tag:"import-script",
    selectArea:true,
    addItems:[
        {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"virtual", "sub-type":"jalousie120", "length":"1"},
    ],
    vars:[
        {type:"comment",text:"Введите название для устройства:"},
        {name:"NAME",type:"string",required:true,min:3,max:40},
        {type:"comment",text:"Введите время хода мотора:"},
        {name:"TIME",type:"number",required:true,min:0},
        {name:"JALOUSIE",type:"hidden",value:"%TARGET%:%SUBID%"},
        {name:"OPENB",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Открыть б",descWidth:100},
        {name:"CLOSEB",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Закрыть б",descWidth:100},
        {name:"OPENM",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Открыть М",descWidth:100},
        {name:"CLOSEM",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Закрыть М",descWidth:100},
        {name:"OBSHB",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Общий Б",descWidth:100},
        {name:"OBSHM",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Общий М",descWidth:100},
    ]
}
*/
u8 i=0;
u8 statusOfJalousie = 0;

void openJalousie(){
    statusOfJalousie = 1;
    setStatus(JALOUSIE, statusOfJalousie);
    setStatus(OPENB, 0);
    setStatus(OPENM, 0);
    setStatus(OBSHB, 0);
    setStatus(OBSHM, 0);
}
void closeJalousie(){
    statusOfJalousie = 0;
    setStatus(JALOUSIE, statusOfJalousie);
    setStatus(CLOSEB, 0);
    setStatus(CLOSEM, 0);
    setStatus(OBSHB, 0);
    setStatus(OBSHM, 0);
}

void onInit()
{
srvError("Перезагрузка состояния rhx %d",[JALOUSIE.0] );
if ([JALOUSIE.0]==1) {statusOfJalousie=1; srvError("%d", statusOfJalousie);} else
if ([JALOUSIE.0]==4) {statusOfJalousie=4; srvError("%d", statusOfJalousie);}
}


V-ID/JALOUSIE {
    // пришла команда открыть
    if(opt(0) == 1) {
    
        if(statusOfJalousie == 0 || statusOfJalousie == 4) {
            // если было закрыто - открыть
            statusOfJalousie = 3;
            setStatus(JALOUSIE, statusOfJalousie);
            delayedCall(openJalousie, TIME);
            setStatus(OPENB, 1);
            setStatus(OPENM, 1);
            setStatus(OBSHB, 1);
            setStatus(OBSHM, 1);
            }
    }
    
    // пришла команда закрыть
    if(opt(0) == 0) {
    
        if(statusOfJalousie == 1 || statusOfJalousie == 4 || i==0) {
            // если было открыто или где-то по середине - закрыть
            i=1;
            statusOfJalousie = 2;
            setStatus(JALOUSIE, statusOfJalousie);
            delayedCall(closeJalousie, TIME);
            setStatus(CLOSEB, 1);
            setStatus(CLOSEM, 1);
            setStatus(OBSHB, 1);
            setStatus(OBSHM, 1);
        }
    }

if(opt(0)==0xFF){
		statusOfJalousie = 4;
		setStatus(JALOUSIE, statusOfJalousie);
		cancelDelayedCall(closeJalousie);
		cancelDelayedCall(openJalousie);
        setStatus(OPENB, 0);
        setStatus(OPENM, 0);

        setStatus(CLOSEB, 0);
        setStatus(CLOSEM, 0);

        setStatus(OBSHB, 0);
        setStatus(OBSHM, 0);
	}

}