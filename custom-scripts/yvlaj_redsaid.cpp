/*
{
	desc:"Чудо увлажнители",
	tag:"import-script",
	selectArea:true,
	
	vars:[

{name:"H0",type:"devices-list",required:true,width:1000,filter:["conditioner"],desc:"Увлажнитель 0",descWidth:100},


{name:"B0",type:"devices-list",required:true,width:1000,filter:["lamp"],desc:"лампа 0",descWidth:100},

{name:"D0",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 0",descWidth:100},


	]
}
*/

u8 i[9];

void off()
{
setStatus(B0, 0);
}

V-ID/s:10
{
if( (i[0]==1) && ([H0.1]>[D0.1]) ) 
{
    setStatus(B0, 1);
}
else
{
   setStatus(B0, 0); 
}
//delayedCall(off, 1); // выключение через заданное количество секунд
}

V-ID/H0
{
	if([H0.0]%2!=0 ) i[0]=1; else i[0]=0;
}
