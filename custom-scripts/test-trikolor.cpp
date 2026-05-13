/*
{
    desc:"Выкл при ребуте",
    tag:"import-script",
    name:"Выкл при ребуте",
    selectArea:true,
    vars:[
    {type:"comment",text:"Лампа, которую выключать при перезапуске по питанию:"},
    {name:"U00",type:"devices-list",required:false,filter:["lamp"],width:888,desc:"Устройство"},
    ]
}
*/

void onInit()
{
    setStatus(U00,0)
}