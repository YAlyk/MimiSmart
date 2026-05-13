/*
{
	desc:"Чудо увлажнители",
	tag:"import-script",
	selectArea:true,
	
	vars:[

{name:"H0",type:"devices-list",required:true,width:1000,filter:["conditioner"],desc:"Увлажнитель 0",descWidth:100},
{name:"H1",type:"devices-list",required:true,width:1000,filter:["conditioner"],desc:"Увлажнитель 1",descWidth:100},
{name:"H2",type:"devices-list",required:true,width:1000,filter:["conditioner"],desc:"Увлажнитель 2",descWidth:100},


{name:"B0",type:"devices-list",required:true,width:1000,filter:["lamp"],desc:"лампа 0",descWidth:100},
{name:"B1",type:"devices-list",required:true,width:1000,filter:["lamp"],desc:"лампа 1",descWidth:100},
{name:"B2",type:"devices-list",required:true,width:1000,filter:["lamp"],desc:"лампа 2",descWidth:100},


{name:"D0",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 0",descWidth:100},
{name:"D1",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 1",descWidth:100},
{name:"D2",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 2",descWidth:100},


	]
}
*/

u8 i[9];

void off()
{
setStatus(B0, 0);
setStatus(B1, 0); 
setStatus(B2, 0); 
}

V-ID/s:10
{
if( (i[0]==1) && ([H0.1]+10>[D0.1]) ) 
{
    setStatus(B0, 1);
}
else
{
   setStatus(B0, 0); 
}

if( (i[1]==1) && ([H1.1]+10>[D1.1]) ) 
{
    setStatus(B1, 1);
}
else
{
   setStatus(B1, 0); 
}

if( (i[2]==1) && ([H2.1]+10>[D2.1]) ) 
{
    setStatus(B2, 1);
}
else
{
   setStatus(B2, 0); 
}

//delayedCall(off, 1); // выключение через заданное количество секунд
}

V-ID/H0
{
	if([H0.0]%2!=0 ) i[0]=1; else i[0]=0;
}

V-ID/H1
{
	if([H1.0]%2!=0 ) i[1]=1; else i[1]=0;
}

V-ID/H2
{
	if([H2.0]%2!=0 ) i[2]=1; else i[2]=0;
}