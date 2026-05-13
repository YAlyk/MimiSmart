/*
{
  desc:"вытяжка",
  tag:"item",
  name:"вытяжка",
  selectArea:true,
  vars:[
  {name:"VIT", type:"devices-list", required:true, filter:["conditioner"], desc:"Вытяжка"}, 
  {name:"GIST", type:"number", defaultValue:10, required:true, desc:"Гистерезис x 10",
  descWidth:370},
  {name:"SPEED1",type:"devices-list",required:true,width:800,filter:["lamp"],desc:"Скорость 1",descWidth:100},
  {name:"SPEED2",type:"devices-list",required:true,width:800,filter:["lamp"],desc:"Скорость 2",descWidth:100},
  {name:"VLAJ",type:"devices-list",required:true,width:600,filter:["humidity-sensor"],desc:"Датчик влажности",descWidth:100},
  ]
}
*/


u8 kond[5];

V-ID/s:5
{
	
    u16 pokazanie=([VLAJ.1] * 10); // берем влажность с датчика и умножаем на 10 для удобства
    // проверка, если 2 скорости включены, то вырубаем все
    if (([SPEED1.0] == 1) && ([SPEED2.0] == 1))
    {
    	setStatus(SPEED1, 0);
      setStatus(SPEED2, 0);
    }
    if ([VIT.4] == 0) // авто режим
    {
      getStatus(VIT, &kond); // берем состояние вытяжки
      // создаем интервал для 1 скорости
      if (((pokazanie + GIST) <= 280) && ((pokazanie + GIST) >= 260)) // 500 and 270
      {
      	kond[1] = 1;
      	setStatus(VIT, kond);
        setStatus(SPEED1, 1);
        setStatus(SPEED2, 0);
      }
      // включение 2 скорости при условии, что влажность больше N-ного значения
      else if ((pokazanie + GIST) >280) // 500
      {
      	kond[1] = 2;
      	setStatus(VIT, kond);
        setStatus(SPEED1, 0);
        setStatus(SPEED2, 1);
      }
      // вырубаем, если влажность меньше N-ного значения
      else if ((pokazanie - GIST) < 260) // 270
      {
      	kond[1] = 0;
      	//setStatus(VIT, kond);
      	setStatus(SPEED1, 0);
      	setStatus(SPEED2, 0);
      }
    }
}

V-ID/VIT
{
  // ручной режим
    if([VIT.4] == 1) 
    {
    	//srvError("че в первом байте: %d", [VIT.1]);
      // смотрим на цифирки в кнопке и выставляем режимы в зависимости от этого
        if([VIT.1]==0) 
        {
        	//srvError("вырубили кондей");
        	setStatus(SPEED2, 0);
        	setStatus(SPEED1, 0);
        }
        if([VIT.1]==1) 
        {
          //srvError("зашли в 1 скорость");
          setStatus(SPEED1, 1); 
          setStatus(SPEED2, 0); 
        }
        if([VIT.1]==2)
        {
        	//srvError("зашли в 2 скорость");
        	setStatus(SPEED1, 0); 
        	setStatus(SPEED2, 1); 	
        }
    } 
    // если по каким-то причинам выходим за границы, то вырубаем все
    else
    {
    	kond[1] = 0;
      //setStatus(VIT, kond);
    	setStatus(SPEED1, 0); 
    	setStatus(SPEED2, 0);
    }
}