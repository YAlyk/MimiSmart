/*
{
      desc:"Конвектор и скорости",
      name:"Конвектор и скорости",
      tag:"import-script",
      selectArea:true,
      addItems:[
            {tag:"item", id:"%TARGET%", name:"Отопление", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"12", "t-min":"18", "modes":"0x00","funs":"0x0F","vane-hor":"0x00", "vane-ver":"0x00"},
      ],
      vars:[
            {name:"SPEED01", type:"devices-list",filter:["lamp"], required:true,  desc:"Скорость 1"},
            {name:"SPEED02", type:"devices-list",filter:["lamp"], required:true,  desc:"Скорость 2"},
            {name:"VALVE", type:"devices-list",filter:["valve-heating"], required:true,  desc:"Отопление"},
            {name:"COND",type:"hidden",value:"%TARGET%:%SUBID%"}
      ]
}
*/

V-ID/s:5{
      if(([COND.0]%2)==1){
            // Режим и температура
            if(([VALVE.5]==255) || ([VALVE.5]==254)) {setStatus(1000:100, "Авто");}
            else if([VALVE.2]!=[COND.1]+18){u8 temp = [COND.1]+18; setStatus(1000:102, {"VALVE\0t:"A, temp,0});}
            // Скорости
            if(([VALVE.0]&1)==1){
                  if([COND.4]==0){setStatus(SPEED01, 0); setStatus(SPEED02, 0);}
                  else if([COND.4]==1){setStatus(SPEED02, 0); setStatus(SPEED01, 1);}
                  else if([COND.4]==2){setStatus(SPEED01, 0); setStatus(SPEED02, 1);}
            } 
            else {setStatus(SPEED01, 0); setStatus(SPEED02, 0);}
      }
      else {
            if([VALVE.5]==!254) {
                  setStatus(SPEED01, 0);
                  setStatus(SPEED02, 0);
                  setStatus(1000:102,"VALVE\0as:-1");
            }
      }
}