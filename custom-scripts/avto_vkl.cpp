/*
{
  desc:"АвтоВключение",
  tag:"item",
  name:"АвтоВключение",
  selectArea:true,
  vars:[
	{name:"I00",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 1"},
	{name:"I01",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 2"},
	{name:"I02",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 3"},
	{name:"I03",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 4"},
	{name:"I04",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 5"},
	{name:"I05",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 6"},
	{name:"I06",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 7"},
	{name:"I07",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 8"},
	{name:"I08",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 9"},
	{name:"I09",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 10"},
	{name:"I10",type:"devices-list",required:false, filter:["lamp", "script", "dimer-lamp"],desc:"Включать 11"},
	]
}
*/

void autoOn(){
	if(([V-ADDR.0]&1)==1){
		#ifdef I00 setStatus(I00, 1); #endif
		#ifdef I01 setStatus(I01, 1); #endif
		#ifdef I02 setStatus(I02, 1); #endif
		#ifdef I03 setStatus(I03, 1); #endif
		#ifdef I04 setStatus(I04, 1); #endif
		#ifdef I05 setStatus(I05, 1); #endif
		#ifdef I06 setStatus(I06, 1); #endif
		#ifdef I07 setStatus(I07, 1); #endif
		#ifdef I08 setStatus(I08, 1); #endif
		#ifdef I09 setStatus(I09, 1); #endif
		#ifdef I10 setStatus(I10, 1); #endif
	}
}

void onInit(){
	setStatus(V-ADDR, 1);
	delayedCall(autoOn, 5);
}