/*
{
    desc:"Выкл. кондеи",
    tag:"item",
    name:"Выкл. кондеи",
    selectArea:true,
    vars:[
    {type:"comment",text:"кондеи, которые надо выключить",width:200, style:"color:red;"},
    {name:"COND", type:"devices-list", required:true, filter:["conditioner"], descWidth:370, desc:"Кондиционер"},
    {type:"comment",text:"скрипт на выкл всего",width:200, style:"color:red;"},
    {name:"SCR", type:"device-list", requared:true, filter:["script"], descWidth:370, desc:"скрипт"},
    ]
}
*/

u8 k[5];

void yuliya(){
    setStatus(V-ADDR, 0);
}

V-ID/SCR{
    getStatus(COND, &k);
    k[0]=k[0]&0xFE;
    setStatus(COND, &k);
    delayedCallR(yuliya, 1);
    
}