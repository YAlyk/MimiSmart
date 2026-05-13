/*
{
  desc:"Полная охрана c дополнительными функциями по сработке",
  
  tag:"item",

  selectArea:false,
  vars:[
   	{name:"MOTION0",type:"devices-list",required:true, filter:["motion-sensor"],desc:"Датчик движения1"},
   	{name:"MOTION1",type:"devices-list",required:true, filter:["motion-sensor"],desc:"Датчик движения2"},
	{name:"MOTION2",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения3"},
   	{name:"MOTION3",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения4"},
   	{name:"MOTION4",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения5"},
   	{name:"MOTION5",type:"devices-list",required:false, filter:["motion-sensor"],desc:"Датчик движения6"},
   	{name:"MIG",type:"devices-list",required:false, filter:["rgb-lamp"],desc:"Мигалка"},
   	{name:"MRMR",type:"devices-list",required:false, filter:["speaker"],desc:"Точка на которую вещать"},
	{name:"VOLUME",type:"number",required:false,width:100,defaultValue:200,min:0,max:250,desc:"Громкость оповещения"},	
    {name:"NUMBER","type":"string","required":false,"width":130,"filter":"0-9\\+","min":3,"max":15,"defaultValue":"+38067777777","desc":"Номер телефона, пример - +38067 7777 777","descWidth":230},
	]
}
*/

u32 time = 5;
u16 porog = 0x2000; // treshold
u8 statutOn = 0;
u8 statutOff = 0;
u8 alarm = 0;
//VOLUME = 200;

V-ID/s:1
{
	if (alarm == 1) {
//		setStatus(711:8,0xff);
//		setStatus(711:9,0xff);
//		setStatus(711:10,0xff);
	}
}


void redon(){
	setStatus(MIG,{1, 250, 250, 250, 0});
}
void redoff(){
	setStatus(MIG,{0, 250, 250, 250, 0});
}
void blueon(){
	setStatus(MIG,{1, 250, 250, 160, 0});
}
void rblueoff(){
	setStatus(MIG,{0, 250, 250, 160, 0});
}
void police(){
	delayedCallMs (blueon, 		50);
	delayedCallMs (rblueoff, 	100);
	delayedCallMs (blueon, 		150);
	delayedCallMs (rblueoff, 	200);
	delayedCallMs (blueon, 		300);
	delayedCallMs (rblueoff, 	350);	
	delayedCallMs (redon, 		650);
	delayedCallMs (redoff, 		700);
	delayedCallMs (redon, 		750);
	delayedCallMs (redoff, 		800);
	delayedCallMs (redon, 		900);
	delayedCallMs (redoff, 		950);	
}


void alarm(){
	alarm = 1;
	#ifdef MRMR
		setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/alarm.mp3"});
		setStatus(1055:17, {1, 0, 0, "NUMBER#"A, toUcs2(65001, "Тревога!")});
	#endif
	setStatus(2047:32, {1,"Тревога!"});
	delayedCall  (police, 0);
	delayedCallMsR (police, 1700);	
	//setStatus(1055:16, {2, 1, 5, 0, "NUMBER#/MENUSEC/MENU.TXT"});
}

//постановка
void on(){

            if(([MOTION0]<porog) && ([MOTION1]<porog)){				
				statutOn = 1;
				statutOff = 1;
				setStatus(2047:32, {1,"Под охраной"});				
					#ifdef MRMR 
					#ifdef VOLUME
					setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/поставлено.mp3"});
					setStatus(1055:17, {1, 0, 0, "NUMBER#"A, toUcs2(65001, "Под охраной")});
					#endif 
					#endif
			}else {
				statutOn = 0;
				statutOff = 0;
                //setStatus(2047:32, {1,"Не успели выйти, повторите попытку"});
				setStatus(V-ADDR,0);			 
					#ifdef MRMR 
					#ifdef VOLUME
					setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/не_успели.mp3"});
					#endif
					#endif
			}
			// all light off
			//setStatus(557:200,1);
}

//снятие
void off(){
    if (![V-ADDR]){
  	 		setStatus(2047:32, {1,"Без охраны"});
			cancelDelayedCall (police);			
			setStatus(573:24,{0, 0xFE, 0xFE, 0xFE, 0});
					#ifdef MRMR 
					#ifdef VOLUME
				setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/снято.mp3"});
				setStatus(1055:17, {1, 0, 0, "NUMBER#"A, toUcs2(65001, "Без охраны")});
				#endif	
				#endif
				alarm = 0;
//		setStatus(711:8,0);
//		setStatus(711:9,0);
//		setStatus(711:10,0);
	}else{
  		 alarm();
	 }
}


//сработака
V-ID/
{
	if ([V-ADDR]){
    		   if (statutOff && statutOn){    
					if (([~MOTION0]>porog) || ([~MOTION1]>porog)) { 
						statutOff = 0;
						delayedCall (off, 10); //время снятия				
					#ifdef MRMR 
					#ifdef VOLUME
							setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/снятие.mp3"});         
							#endif
							#endif
					}
				}		
	}
}

V-ID/V-ADDR
{
	if(opt(0)){		 
		 statutOn = 1;
		 delayedCall (on, 13);//время выхода 		 
					#ifdef MRMR 
					#ifdef VOLUME
				setStatus(MRMR,{1, VOLUME, 1, "http://192.168.1.125/постановка.mp3"});
				#endif
				#endif
	}else{
			if(statutOn){
				off();
				cancelDelayedCall(off); 
				cancelDelayedCall(on); 
			}
		}
}
