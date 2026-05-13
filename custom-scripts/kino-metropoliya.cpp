/*
{
	desc:"Кино",
	tag:"item",
	selectArea:true,
	vars:[
		{name:"D00",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
		{name:"D01",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
		{name:"D02",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
		{name:"D03",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
		{name:"D04",type:"devices-list",required:false,width:800,filter:["dimer-lamp"],desc:"Диммер",descWidth:100},
		{name:"L00",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L01",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L02",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L03",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L04",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L05",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L06",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L07",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"L08",type:"devices-list",required:false,width:800,filter:["lamp"],desc:"Лампа",descWidth:100},
		{name:"B00",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Штора 1",descWidth:100},
        {name:"B01",type:"devices-list",required:false,width:800,filter:["jalousie"],desc:"Штора 2",descWidth:100},
		{name:"ON",type:"devices-list",filter:["script"],required:false,width:800,desc:"Вкл проектор",descWidth:100},
		{name:"OFF",type:"devices-list",filter:["script"],required:false,width:800,desc:"Выкл проектор",descWidth:100},
		]
}
*/

u8 onoff[5]={0, 0, 0, 0, 0};
u8 bright[5]={0, 0, 0, 0, 0};
u8 more=0;
u8 stateBright = 0;

void razgoranie(){
	more=0;
	if(onoff[0] && (bright[0]<[D00.1])) {setStatus(D00, {onoff[0], [D00.1]+5, 0}); more=1;}
	if(onoff[1] && (bright[1]<[D01.1])) {setStatus(D01, {onoff[1], [D01.1]+5, 0}); more=1;}
	if(onoff[2] && (bright[2]<[D02.1])) {setStatus(D02, {onoff[2], [D02.1]+5, 0}); more=1;}
	if(onoff[3] && (bright[3]<[D03.1])) {setStatus(D03, {onoff[3], [D03.1]+5, 0}); more=1;}
	if(onoff[4] && (bright[4]<[D04.1])) {setStatus(D04, {onoff[4], [D04.1]+5, 0}); more=1;}
	if(more) delayedCallMs(razgoranie, 250);
}

void zatuhanie(){
	stateBright = [D00.1];
	if(stateBright-5>0) setStatus(D00, {0xFE, stateBright-5, 0});
	stateBright = [D01.1];
	if(stateBright-5>0) setStatus(D01, {0xFE, stateBright-5, 0});
	stateBright = [D02.1];
	if(stateBright-5>0) setStatus(D02, {0xFE, stateBright-5, 0});
	stateBright = [D03.1];
	if(stateBright-5>0) setStatus(D03, {0xFE, stateBright-5, 0});
	stateBright = [D04.1];
	if(stateBright-5>0) setStatus(D04, {0xFE, stateBright-5, 0});
	// Если у всех маленькая яркость - выключаем!
	if( ([D00.1]<=5) && ([D01.1]<=5) && ([D02.1]<=5) && ([D03.1]<=5) && ([D04.1]<=5) ){
		setStatus(D00, {0, 0, 0}); setStatus(D01, {0, 0, 0}); setStatus(D02, {0, 0, 0}); setStatus(D03, {0, 0, 0}); setStatus(D04, {0, 0, 0});
	}
	else delayedCallMs(zatuhanie,250);
}

// Запоминаем состояние диммеров
void remember(){
	onoff[0]=([D00.0]&1);
	onoff[1]=([D01.0]&1);
	onoff[2]=([D02.0]&1);
	onoff[3]=([D03.0]&1);
	onoff[4]=([D04.0]&1);
	bright[0]=[D00.1]; srvError("Запомнили яркость 0 = %d", bright[0]);
	bright[1]=[D01.1]; srvError("Запомнили яркость 1 = %d", bright[1]);
	bright[2]=[D02.1]; srvError("Запомнили яркость 2 = %d", bright[2]);
	bright[3]=[D03.1]; srvError("Запомнили яркость 3 = %d", bright[3]);
	bright[4]=[D04.1]; srvError("Запомнили яркость 4 = %d", bright[4]);
	zatuhanie();
}


V-ID/V-ADDR{
	if((opt(0)&1)==1){
		cancelDelayedCall(zatuhanie);
		cancelDelayedCall(razgoranie);
		remember();
		setStatus(L00, 0);
		setStatus(L01, 0);
		setStatus(L02, 0);
		setStatus(L03, 0);
		setStatus(L04, 0);
		setStatus(L05, 0);
		setStatus(L06, 0);
		#ifdef L07 setStatus(L07, 0); #endif
		#ifdef L08 setStatus(L08, 0); #endif
		setStatus(B00, 0);
		setStatus(ON, 1);
	} else if((opt(0)&1)==0){
		bright[0]=[D00.1]; srvError("Загрузили яркость 0 = %d", bright[0]);
		bright[1]=[D01.1]; srvError("Загрузили яркость 1 = %d", bright[1]);
		bright[2]=[D02.1]; srvError("Загрузили яркость 2 = %d", bright[2]);
		bright[3]=[D03.1]; srvError("Загрузили яркость 3 = %d", bright[3]);
		bright[4]=[D04.1]; srvError("Загрузили яркость 4 = %d", bright[4]);
		cancelDelayedCall(zatuhanie);
		cancelDelayedCall(razgoranie);
		razgoranie();
		setStatus(OFF, 1);
	}
}