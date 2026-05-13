/*
{
	desc:"Камин",
	tag:"import-script",
	selectArea:true,
	
	vars:[
    {name:"VKL",type:"devices-list",required:true,width:1000,filter:["script"],desc:"Вкл",descWidth:100},
    {name:"VIKL",type:"devices-list",required:true,width:1000,filter:["script"],desc:"Выкл",descWidth:100},
    {name:"SPEED",type:"devices-list",required:true,width:1000,filter:["script"],desc:"Скорость",descWidth:100},
    {name:"COLOR",type:"devices-list",required:true,width:1000,filter:["script"],desc:"Выбор цвета",descWidth:100},
    {name:"MODECOLOR",type:"devices-list",required:true,width:1000,filter:["script"],desc:"Режим цвета",descWidth:100},
    {name:"CUTOFF",type:"number",required:true,width:100,defaultValue:1,min:1,max:180,desc:"Время отсечки"},
    {name:"RS485",type:"devices-list",required:true,width:600,filter:["com-port"],desc:"РСка",descWidth:100},
	]
}
*/

// лог рски
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

// отсечка
void AllOff()
{
    setStatus(VKL, 0);
    setStatus(VIKL, 0);
    setStatus(SPEED, 0);
    setStatus(COLOR, 0);
    setStatus(MODECOLOR, 0);
}

//работает
V-ID/VKL
{
    if(opt(0)==1)
	{	
        u8 i[8]={0x01, 0x06, 0x20, 0x01, 0x00, 0x01, 0xCC, 0x16};
        setStatus(RS485,&i);
        delayedCall(AllOff, CUTOFF);
    }

}

//работает
V-ID/VIKL
{
    if(opt(0)==1)
	{	
        u8 i[8]={0x01, 0x06, 0x20, 0x01, 0x00, 0x00, 0xCC, 0x16};
        setStatus(RS485,&i);
        delayedCall(AllOff, CUTOFF);
    }

}

//вкл 5 скорости
V-ID/SPEED
{
    if(opt(0)==1)
	{	
        u8 i[8]={0x01, 0x06, 0x20, 0x02, 0x00, 0x05, 0xCC, 0x16};
        setStatus(RS485,&i);
        delayedCall(AllOff, CUTOFF);
    }

}

//не доделал.
V-ID/COLOR
{
    if(opt(0)==1)
	{	
        u8 i[8]={0x01, 0x06, 0x20, 0x04, 0x00, 0x04, 0xCC, 0x16};
        setStatus(RS485,&i);
        delayedCall(AllOff, CUTOFF);
    }

}

//не доделал.
V-ID/MODECOLOR
{
    if(opt(0)==1)
	{	
        u8 i[8]={0x01, 0x06, 0x20, 0x07, 0x00, 0x00, 0xCC, 0x16};
        setStatus(RS485,&i);
        delayedCall(AllOff, CUTOFF);
    }

}

V-ID/RS485
{
  stat();
}