/*
{
	desc:"тест геркона",
	tag:"import-script",
	selectArea:true,
	
	vars:[
    {name:"V0",type:"devices-list",required:true,width:1000,filter:["door-sensor"],desc:"геркон",descWidth:100},
	]
}
*/

V-ID/:10
{
    u8 gerkon[1]; 
    getStatus(V0, &gerkon);
    srvError("состояние геркона: ", gerkon[1]);
}