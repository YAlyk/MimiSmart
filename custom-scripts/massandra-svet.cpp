/*{
  desc:"Скрипт для управления элементами с временными интервалами",  tag:"import-script",
  selectArea:true,  vars:[
    {name:"ELEMENT1",type:"devices-list",required:true,filter:["lamp"],desc:"Первый свет с автоматизацией",descWidth:300,width:300},
    {name:"ELEMENT2",type:"devices-list",required:true,filter:["lamp"],desc:"Второй свет без автоматизации",descWidth:300,width:300},
    {name:"BUTTON",type:"devices-list",required:true,filter:["switch"],desc:"Кнопка которая будет управлять",descWidth:300,width:300},
    ]
}*/


// 0xFF - отжатие клавиши
// 0xFD - удержание клавиши
// 0хFC - нажатие на клавишу

V-ID/BUTTON{  
  if([BUTTON.0]==0xFD){
    setAutoState(ELEMENT1, -1);
    setStatus(ELEMENT1, 1);
    setStatus(ELEMENT2, 1);
    i8 sttOfAuto = autoState(ELEMENT1);
    if(sttOfAuto < 0) {
    	srvError("Автоматизация выключена!");
    }
  }
  else{
    setAutoState(ELEMENT1, 0);
    setStatus(ELEMENT1, 0);
    setStatus(ELEMENT2, 0);
    i8 sttOfAuto = autoState(ELEMENT1);
    if(sttOfAuto == 0) {
        	srvError("Автоматизация включена!");
    }
  }
}