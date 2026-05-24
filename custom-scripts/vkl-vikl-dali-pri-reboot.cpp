/*
{
  desc:"Выключение дали",
  
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"I00",type:"devices-list",required:true, filter:["dimer-lamp"],desc:"Диммер 0"},
    {name:"I01",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 1"},
    {name:"I02",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 2"},
    {name:"I03",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 3"},
    {name:"I04",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 4"},
    {name:"I05",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 5"},
    {name:"I06",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 6"},
    {name:"I07",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 7"},
    {name:"I08",type:"devices-list",required:false, filter:["dimer-lamp"],desc:"Диммер 8"},
]
}
*/

void OFF(){
    setStatus(I00, 0);
    setStatus(I01, 0);
    setStatus(I02, 0);
    setStatus(I03, 0);
    setStatus(I04, 0);
    setStatus(I05, 0);
    setStatus(I06, 0);
    setStatus(I07, 0);
    setStatus(I08, 0);
}

void onInit(){
	setStatus(I00, 1);
    setStatus(I01, 1);
    setStatus(I02, 1);
    setStatus(I03, 1);
    setStatus(I04, 1);
    setStatus(I05, 1);
    setStatus(I06, 1);
    setStatus(I07, 1);
    setStatus(I08, 1);
    delayedCall(OFF, 1);
}