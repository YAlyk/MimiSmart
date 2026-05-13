/*
{
	desc:"Кастом вентиляция казак",
	tag:"import-script",
	selectArea:true,
	
	vars:[
    {name:"V0",type:"devices-list",required:true,width:1000,filter:["door-sensor"],desc:"Вытяжка кухни",descWidth:100},
    {name:"L0",type:"devices-list",required:true,width:1000,filter:["lamp","script"],desc:"Установка",descWidth:100},
    {name:"SPOT",type:"devices-list",required:true,width:1000,filter:["lamp","script"],desc:"Свет",descWidth:100},
	]
}
*/
// у геркона приоритет 1, у спотов 2 (чем меньше, тем выше приоритет), у времени 3
// V0 это геркон на вытяжке кухни
// L0 == 0 => включено на гост, L0 == 1 => включено на спальню

u8 sostoianie = 0;

V-ID/V0
{
 if ([V0.0]==0){
        setStatus(L0, 0);
        //srvError("вкл из-за геркона на гост");
        }
    else{
        setStatus(L0, 1);
        //srvError("выкл из-за геркона на спальню");
  }
}

V-ID/SPOT
{
    if([SPOT.0]==1 && [V0.0]==1){
        setStatus(L0, 1);
      //srvError("вкл на спальню из-за спотов 1 и геркон 1");
  }
    else{
        setStatus(L0, 0);
        //srvError("вкл на гост из-за спотов и/или геркон 1");
    }
}

// V-ID/s:10
// {
// 	// в выхи с 23\00-11\00, в будни с 23\00 - 9\00

// // будни
//     u8 res = timeInRange(23:01-09:01|mo, tu, we, th, fr);
//     if (res!=0){
//     	if(res!=0 && [V0.0]==1){
//       	setStatus(L0, 1);
//         	srvError("вкл на спальню по времени ночь в будни");
//     	}
//     	else{
//     		setStatus(L0, 0);
//     		srvError("вкл на гостиную (ночь) сработка геркона или вкл споты в будни");
//     	}
//     }
//     u8 res1 = timeInRange(09:01-23:01|mo, tu, we, th, fr);
//     if (res1!=0){
//     	if(res1==0 && [SPOT.0]==0){
//         	setStatus(L0, 0);
//         	srvError("вкл на гостиную по времени день в будни");
//         	srvError("res1= %d", res);
//     	}
//     	else{
//     		setStatus(L0, 1);
//     		srvError("вкл на спальню (день) споты вкл в будни");
//     	}
// 	}

// // выхи
//     u8 res2 = timeInRange(23:01-11:01|sa, su);
//     if (res2!=0){
//     	if(res2!=0 && [V0.0]==1){
//         	setStatus(L0, 1);
//         	srvError("вкл на спальню по времени ночь в выхи");
//     	}
//     	else{
//     		setStatus(L0, 0);
//     		srvError("вкл на гостиную (ночь) сработка геркона или вкл споты в выхи");
//     	}
//     }
//     u8 res3 = timeInRange(11:01-23:01|sa, su);
//     if (res3!=0){
//     	if(res3==0 && [SPOT.0]==0){
//         	setStatus(L0, 0);
//         	srvError("вкл на гостиную по времени день в выхи");
//         	srvError("res3= %d", res);
//     	}
//     	else{
//     		setStatus(L0, 1);
//     		srvError("вкл на спальню (день) споты вкл в выхи");
//     	}
// 	}
// }

    

  V-ID/s:10{
      //изначальный
      u8 res = timeInRange(00:01-09:01);
      if (res!=0){
          if([V0.0]==0){
              setStatus(L0, 0);
          }
          else{
              setStatus(L0, 1);
          }
      }
      else{
          if([V0.0]==0){
              setStatus(L0, 0);
          }
          else{
              setStatus(L0, 0);
          }
      }
 }