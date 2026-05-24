/*
{
  desc:"Автоматизация скорости вентиляции по СО2",
  name:"АвтоСкорости",
  tag:"item",
  selectArea:true,
  vars:[
    {name:"VENT",type:"devices-list",required:true, filter:["conditioner"],desc:"Вентиляция"},
    {name:"CO200",type:"devices-list",required:true, filter:["co2-sensor"],desc:"Датчик CO2"},
    {name:"DANGERHI",type:"number",min:"400",max:"1500",required:true,defaultValue:"1000",desc:"Порог максимум"},
    {name:"DANGERMED",type:"number",min:"400",max:"1500",required:true,defaultValue:"800",desc:"Порог средний"},

	]
}
*/

u8 state[5];
u16 pokazanie0 = 0;

void onInit(){
  setStatus(V-ADDR, 1);
}

V-ID/s:15{

  pokazanie0 = (([CO200.0]*100/255)+([CO200.1]*100));

  if(([V-ADDR.0]&1) == 1){
    // Если показания выше чем максимум - включаем скорость максимум
    if(pokazanie0 > DANGERHI){
      getStatus(VENT, state);
      state[0] = 1;
      state[4] = 2;
      setStatus(VENT, &state);
    }
    else if(pokazanie0 > DANGERMED){
      getStatus(VENT, state);
      state[0] = 1;
      state[4] = 1;
      setStatus(VENT, &state);
    } else {
      getStatus(VENT, state);
      state[0] = 1;
      state[4] = 0;
      setStatus(VENT, &state);
    }
  }
}