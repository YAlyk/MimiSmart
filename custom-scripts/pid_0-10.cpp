/*
{
  desc:"Регулировка клапаном подачи теплоносителя в контур",
  tag:"import-script",
  selectArea:true,
  addItems:[
    {tag:"item", id:"%TARGET%", name:"NAME", "sub-id":"%SUBID%", type:"conditioner", "t-delta":"70", "t-min":"10", "vane-ver":"0x00", "vane-hor":"0x00", "modes":"0x00", "funs":"0x00"},
  ],
  vars:[
    {name:"TEMP",type:"hidden",value:"%TARGET%:%SUBID%"},
    {name:"CONDSTART", type:"number", defaultValue:22, required:true, desc:"Минимальная температура"},
    {name:"D00", type:"devices-list", required:true, filter:["temperature-sensor"], desc:"Датчик температуры", descWidth:370},
    {name:"G00", type:"number", defaultValue:20, required:true, desc:"Гистерезис"},
    {name:"TIME", type:"number", defaultValue:60, required:true, desc:"Время опроса, с"},
    {name:"L00",type:"devices-list",required:true,width:600,filter:["dimer-lamp"],desc:"Клапан 0-10В",descWidth:100},
    {name:"L01",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Насос",descWidth:100},
    {name:"L02",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"Сервоприводы",descWidth:100},
    {name:"V0",type:"devices-list",required:true, filter:["valve-heating"],descWidth:150, desc:"Батарея"},
  ]
}
*/

i16 tempK=0;
u8 cond[5];
//u8 i[2]={0, 0}; //ограничитель 0-открытия, 1 - закрытия

V-ID/s:TIME
{ 
//srvError("Chek TP");
  if( ([TEMP.0]%2) == 1 )
  {
    tempK=( [D00.1] ); //Считаем температуру на датчике х10 целая часть
    tempK=tempK+([D00.0]*10)/250; //Считаем температуру на датчике х10 дробная часть
    //srvError("на датчике=%d", tempK);
    u16 tempZ=([TEMP.1]+10); //Считаем температуру уставки х10
    //srvError("Уставка=%d", tempZ);
    u16 dimStatus=([L00.1]);
    //srvError("Процент диммера=%d", dimStatus);
    
if( (tempK < (tempZ-G00)) && dimStatus < 230 ) //Сравнение на открытие
    {
    	srvError("Temp Low. Open");
    	dimStatus=dimStatus+2;
		setStatus(L00, {1, dimStatus, 1});
		srvError("Насос в состонии=%d", [L01.0]&7);
		if ([L01.0]&7==0) {
    		setStatus(L01, 1);
    	}
    } 
    else  if( (tempK >  (tempZ+G00)) && dimStatus > 5 ) //Сравнение на закрытие
    {
		srvError("Temp High. Close");
    	dimStatus=dimStatus-2;
    	setStatus(L00, {1, dimStatus, 1});
    	srvError("Насос в состонии=%d", [L01.0]&7);
		if ([L01.0]&7==0) {
    		setStatus(L01, 1);
    	}
    }
  }
}

V-ID/TEMP
{
  if(opt(0)%2==0)
  {
    setStatus(L00, {0, 0xFE});
    setStatus(L01, 0);
    setStatus(L02, 0);
  }
  else if(opt(0)%2==1)
  {
  	setStatus(L00, {1, 0xFE});
    setStatus(L01, 1);
    setStatus(L02, 1);
  }
}