/*
{
	desc:"Работа с телеграмм бот @smart48.ru - Отправка текстовых сообщений, скриншотов и видео c камеры",
	tag:"item",
	selectArea:true,
	vars:[
		{type:"comment",text:"Настройка ТЕЛЕГРАММ получателя",width:888, style:"color:red;"},
		{name:"TELEGRAMMID_1",type:"string",required:true,desc:"Укажите id получателя в телеграмм-боте",width:880},		
		{name:"TXT_1",type:"string",required:true,desc:"Текст уведомления",width:880},
		{name:"TXT_2",type:"string",required:true,desc:"Текст уведомления",width:880},
		{name:"TXT_3",type:"string",required:true,desc:"Текст уведомления",width:880},
		{name:"CAM_ACT1",type:"list",required:true,data:{"1":"1 - Только текст","2":"2 - Текст + Фото","3":"3 - Текст + Видео"},desc:"Присылать текст, Текст+фото или Текст+видео",descWidth:170},
		{name:"CAM1_1",type:"devices-list",required:false, filter:["rtsp"],desc:"Камера 1",descWidth:170},
		{name:"CAM2_1",type:"devices-list",required:false, filter:["rtsp"],desc:"Камера 2",descWidth:170},
		{name:"CAM3_1",type:"devices-list",required:false, filter:["rtsp"],desc:"Камера 3",descWidth:170},
		{name:"REC1_CAM1",type:"number",required:false,min:1,max:60,desc:"Сколько секунд записывать видео - камера 1",descWidth:340,width:100},
		{name:"ANTIFLOOD_1",type:"number",required:false,min:0,max:600,defaultValue:60,desc:"Контроль множетсвенной отправки сообщения сек(0 - не контролировать, 0< - интервал игнорирования отправки сообщения)",descWidth:340,width:100},
			
		]
}
*/
u8 f_antiflood=0;

void send() {
	#ifdef CAM_ACT1
	#ifdef TELEGRAMMID_1
	#ifdef TXT_1
	if (CAM_ACT1==1){
	setStatus(1000:90, "TELEGRAMMID_1||TXT_1||||");
	} else if (CAM_ACT1==2) {
	#ifdef CAM1_1
	setStatus(1000:90, "TELEGRAMMID_1||TXT_1||CAM1_1||");
	#endif
	#ifdef CAM2_1
	setStatus(1000:90, "TELEGRAMMID_1||TXT_2||CAM2_1||");
	#endif
	#ifdef CAM3_1
	setStatus(1000:90, "TELEGRAMMID_1||TXT_3||CAM3_1||");
	#endif
	} else if (CAM_ACT1==3) {	
	#ifdef CAM1_1
	setStatus(1000:90, "TELEGRAMMID_1||TXT_1||CAM1_1||REC1_CAM1");
	#endif
	}
	#endif
	#endif
	#endif
	

}

void off() {
	setStatus(V-ADDR, 0);
	}

V-ID/V-ADDR {	
	if (opt(0)==1 || opt(0)==9){
		if (ANTIFLOOD_1 > 0){
			if (f_antiflood==0){
			send();
			f_antiflood =1;	
			}
		}else{
		send();				
		}
		
		delayedCall(off, 2);
		 
	}
}


V-ID/s:ANTIFLOOD_1 {
	f_antiflood=0;	
}