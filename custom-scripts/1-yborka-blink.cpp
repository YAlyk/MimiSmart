/*
{
  desc:"Уборка",
  tag:"item",
  name:"Уборка",
  selectArea:false,
  vars:[
    {name:"LAMP",type:"devices-list",required:true,filter:["lamp","dimmer-lamp"],desc:"Лампа"},
    {name:"SCRIPT",type:"devices-list",required:true,filter:["script"],desc:"Скрипт уборки"},
  ]
}
*/

u8 cleaning = 0;
u8 blink_count = 0;

V-ID/ms:500
{
    if(cleaning && blink_count < 10) { // 5 миганий
        setStatus(LAMP, (blink_count & 1) ? 0 : 1);
        ++blink_count;
        
        if(blink_count >= 10) {
            setStatus(LAMP, 0); // Выключаем после миганий
        }
    }
}

V-ID/V-ADDR
{
    if(([V-ADDR.0]&1)==1) {
        if(!cleaning) {
            cleaning = 1;
            blink_count = 0;
            setStatus(SCRIPT, 1);
        }
    } else {
        if(cleaning) {
            cleaning = 0;
            blink_count = 0;
            setStatus(SCRIPT, 0);
        }
    }
}
