/*{
  desc:"Скрипт для управления элементами с временными интервалами",  tag:"import-script",
  selectArea:true,  vars:[
    {name:"ELEMENT1",type:"devices-list",required:true,filter:["lamp", "dimmer-lamp", "light-scheme", "script"],desc:"Выберите первый элемент для управления",descWidth:300,width:300},
    {name:"START1",type:"time",required:true,desc:"Время начала первого интервала (формат HH:MM)",descWidth:300,width:300},
    {name:"END1",type:"time",required:true,desc:"Время окончания первого интервала (формат HH:MM)",descWidth:300,width:300},    
    {name:"ELEMENT2",type:"devices-list",required:false,filter:["lamp", "dimmer-lamp", "light-scheme", "script"],desc:"Выберите второй элемент для управления",descWidth:300,width:300},
    {name:"START2",type:"time",required:false,desc:"Время начала второго интервала (формат HH:MM)",descWidth:300,width:300},
    {name:"END2",type:"time",required:false,desc:"Время окончания второго интервала (формат HH:MM)",descWidth:300,width:300},    
    {name:"ELEMENT3",type:"devices-list",required:false,filter:["lamp", "dimmer-lamp", "light-scheme", "script"],desc:"Выберите третий элемент для управления",descWidth:300,width:300},
    {name:"START3",type:"time",required:false,desc:"Время начала третьего интервала (формат HH:MM)",descWidth:300,width:300},
    {name:"END3",type:"time",required:false,desc:"Время окончания третьего интервала (формат HH:MM)",descWidth:300,width:300},    
    {name:"ELEMENT4",type:"devices-list",required:false,filter:["lamp", "dimmer-lamp", "light-scheme", "script"],desc:"Выберите четвертый элемент для управления",descWidth:300,width:300},
    {name:"START4",type:"time",required:false,desc:"Время начала четвертого интервала (формат HH:MM)",descWidth:300,width:300},
    {name:"END4",type:"time",required:false,desc:"Время окончания четвертого интервала (формат HH:MM)",descWidth:300,width:300},    
    ]
}*/

void CHECK_INTERVAL1(){
  u8 res = timeInRange(START1-END1);
  if(res != 0) {
  	setAutoState(ELEMENT1, 0); 
  }
  else {    
  	setAutoState(ELEMENT1, 0xFFFE); 
  }
}

void CHECK_INTERVAL2(){
  u8 res = timeInRange(START1-END1);
  if(res != 0) {
  	setAutoState(ELEMENT1, 0); 
  }
  else {    
  	setAutoState(ELEMENT1, 0xFFFE); 
  }
}

void CHECK_INTERVAL3(){
  u8 res = timeInRange(START1-END1);
  if(res != 0) {
  	setAutoState(ELEMENT1, 0); 
  }
  else {    
  	setAutoState(ELEMENT1, 0xFFFE); 
  }
}

void CHECK_INTERVAL4(){
  u8 res = timeInRange(START1-END1);
  if(res != 0) {
  	setAutoState(ELEMENT1, 0); 
  }
  else {    
  	setAutoState(ELEMENT1, 0xFFFE); 
  }
}

// #define CHECK_INTERVAL2(element, start, end) 
//   u8 res = timeInRange(start, end);
//   if(res != 0) {
//   	setAutoState(element, 0); 
//   }
//   else {    
//   	setAutoState(element, 0xFFFE); 
//   }



// Проверка времени для каждого элемента
V-ID/s:60 {  
  CHECK_INTERVAL1();
  CHECK_INTERVAL2();
  CHECK_INTERVAL3();
  CHECK_INTERVAL4();

}
