/*
{
	desc:"влажнитель форсуночный",
	tag:"import-script",
	selectArea:true,
	
	vars:[

{name:"H0",type:"devices-list",required:true,width:1000,filter:["conditioner"],desc:"Увлажнитель 0",descWidth:100},


{name:"B0",type:"devices-list",required:true,width:1000,filter:["lamp"],desc:"Кнопка 0",descWidth:100},


{name:"D0",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 0",descWidth:100},
{name:"D1",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 1",descWidth:100},
{name:"D2",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 0",descWidth:100},
{name:"D3",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 1",descWidth:100},
	]
}
*/

u8 i[9];

i16 t0[16];
i16 t1[16];
i16 t2[16];
i16 t3[16];
i16 t4[16];

void off()
{
    setStatus(B0, 0);
}

V-ID/s:10
{
    t1[0] = [D0.1];
    t2[0] = [D1.1];
    t3[0] = [D2.1];
    t4[0] = [D3.1];
    
    // srvError("значение 1 датчика =  %d", t1[0]);
    // srvError("значение 2 датчика = %d", t2[0]);
    // srvError("значение 3 датчика =  %d", t3[0]);
    // srvError("значение 4 датчика = %d", t4[0]);

    // t0[0] = ([D0.1] + [D1.1] + [D2.1] + [D3.1]) / 4;
    // srvError("среднее значение 4 датчиков = %d", t0[0]);

    // if( (i[0]==1) && ([H0.1]+10>(([D0.1] + [D1.1] + [D2.1] + [D3.1]) / 4)) )

    if( (i[0]==1) && (([D0.1] > [H0.1]+10) || ([D1.1] > [H0.1]+10) || ([D2.1] > [H0.1]+10) || ([D3.1] > [H0.1]+10) ))
    {
        setStatus(B0, 1);
    }
    else
    {
       setStatus(B0, 0); 
    }
}

V-ID/H0
{
	if([H0.0]%2!=0 ) {
        i[0]=1; 
    }
    else
    {
        i[0]=0;
    }
}
