/*
{
  desc:"При запуске выкл отопления",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"L1",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L2",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L3",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L4",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L5",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L6",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L7",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L8",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
    {name:"L9",type:"devices-list",required:true,filter:["valve-heating"],desc:"Отопление"},
]
}
*/
void off1(){
    setStatus(1000:102,"L1\0as:-4");
}

void off2(){
    setStatus(1000:102,"L2\0as:-4");
}

void off3(){
    setStatus(1000:102,"L1\0as:-4");
}

void off4(){
    setStatus(1000:102,"L1\0as:-4");
}

void off5(){
    setStatus(1000:102,"L1\0as:-4");
}

void off6(){
    setStatus(1000:102,"L1\0as:-4");
}

void off7(){
    setStatus(1000:102,"L1\0as:-4");
}

void off8(){
    setStatus(1000:102,"L1\0as:-4");
}
void off9(){
    setStatus(1000:102,"L1\0as:-4");
}

void onInit(){
	delayedCall(off1, 1);
    delayedCall(off2, 2);
    delayedCall(off3, 3);
    delayedCall(off4, 4);
    delayedCall(off5, 5);
    delayedCall(off6, 6);
    delayedCall(off7, 7);
    delayedCall(off8, 8);
    delayedCall(off9, 9);
}