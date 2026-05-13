/*
{
  desc:"Команда на АС3",
  tag:"item",
  name:"Команда",
  selectArea:true,
  vars:[
    {name:"SIGNALON",type:"text",require:true,defaultValue:"Samsung",desc:"КомандаON"},
    {name:"SIGNALOFF",type:"text",require:true,defaultValue:"Samsung",desc:"КомандаOFF"},
    {name:"ID00",type:"text",required:true,defaultValue:"95",filter:"0123456789:",desc:"Адрес скрипта"},
    {name:"IP",type:"text",required:true,defaultValue:"192.168.1.100",filter:"0123456789.",desc:"IP Адрес AC3"}
  ]
}
*/

V-ID/V-ADDR{
  if((opt(0)&1)==1){
    setStatus(1000:ID00, {"addr=IP|command=SIGNALON|"});
    //httpapi.asp?command=setPlayerCmd:play:https://choco.hostingradio.ru:10010/fm  поток радио, например
  } else if((opt(0)&1)==0){
  	setStatus(1000:ID00, {"addr=IP|command=SIGNALOFF|"});
    //httpapi.asp?command=setPlayerCmd:stop стоп команда
    // httpapi.asp?command=setPlayerCmd:vol:50 задать громкость 50
  }
}
