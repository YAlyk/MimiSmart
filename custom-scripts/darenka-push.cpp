/*
{
desc:"Пуши valve-heating",
name:"Пуши отопление",
tag:"import-script",
selectArea:true,

vars:[
    {name:"HF01",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление 1",descWidth:100},
    {name:"HF02",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление 2",descWidth:100},
    {name:"HF03",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление 3",descWidth:100},
    {name:"HF04",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление 4",descWidth:100},
    {name:"HF05",type:"devices-list",required:false,width:800,filter:["valve-heating"],desc:"Отопление 5",descWidth:100},
]
}
*/

u8 prevHF1 = 0xFF;
u8 prevHF2 = 0xFF;
u8 prevHF3 = 0xFF;
u8 prevHF4 = 0xFF;
u8 prevHF5 = 0xFF;


void notifyHF(u8 cur, u8 prev, u8 num) {
    u8 msg[100];
    if (cur == 1 && prev == 0) {
        sprintf(msg, "%cОтопление %d: включено", 1, num);
    } else if (cur == 0 && prev == 1) {
        sprintf(msg, "%cОтопление %d: выключено", 4, num);
    } else {
        sprintf(msg, "%cОтопление %d: состояние изменено (%d -> %d)", 1, num, prev, cur);
    }
    setStatus(2047:32, &msg);
}


V-ID/HF01 {
    u8 cur = opt(0);
    if (prevHF1 == 0xFF) { prevHF1 = cur; return; }
    if (cur == prevHF1) { return; }
    notifyHF(cur, prevHF1, 1);
    prevHF1 = cur;
}

V-ID/HF02 {
    u8 cur = opt(0);
    if (prevHF2 == 0xFF) { prevHF2 = cur; return; }
    if (cur == prevHF2) { return; }
    notifyHF(cur, prevHF2, 2);
    prevHF2 = cur;
}

V-ID/HF03 {
    u8 cur = opt(0);
    if (prevHF3 == 0xFF) { prevHF3 = cur; return; }
    if (cur == prevHF3) { return; }
    notifyHF(cur, prevHF3, 3);
    prevHF3 = cur;
}

V-ID/HF04 {
    u8 cur = opt(0);
    if (prevHF4 == 0xFF) { prevHF4 = cur; return; }
    if (cur == prevHF4) { return; }
    notifyHF(cur, prevHF4, 4);
    prevHF4 = cur;
}

V-ID/HF05 {
    u8 cur = opt(0);
    if (prevHF5 == 0xFF) { prevHF5 = cur; return; }
    if (cur == prevHF5) { return; }
    notifyHF(cur, prevHF5, 5);
    prevHF5 = cur;
}