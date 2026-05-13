/*{
  desc:"Set_Dimm_in_50%",
  tag:"import-script",
  selectArea:true,
  vars:[
    {name:"DIMER0",type:"devices-list",required:true,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER1",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER2",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER3",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER4",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER5",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER6",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER7",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER8",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER9",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER10",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER11",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER12",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER13",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER14",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER15",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER16",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER17",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER18",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
    {name:"DIMER19",type:"devices-list",required:false,width:200,filter:["dimer-lamp", "rgb-lamp"],desc:"Димер-лампа"},
  ]
}*/

void onInit(){
  setStatus(DIMER0, {0xFE, 125});
  #ifdef DIMER1 setStatus(DIMER1, {0xFE, 125}); #endif
  #ifdef DIMER2 setStatus(DIMER2, {0xFE, 125}); #endif
  #ifdef DIMER3 setStatus(DIMER3, {0xFE, 125}); #endif
  #ifdef DIMER4 setStatus(DIMER4, {0xFE, 125}); #endif
  #ifdef DIMER5 setStatus(DIMER5, {0xFE, 125}); #endif
  #ifdef DIMER6 setStatus(DIMER6, {0xFE, 125}); #endif
  #ifdef DIMER7 setStatus(DIMER7, {0xFE, 125}); #endif
  #ifdef DIMER8 setStatus(DIMER8, {0xFE, 125}); #endif
  #ifdef DIMER9 setStatus(DIMER9, {0xFE, 125}); #endif
  #ifdef DIMER10 setStatus(DIMER1, {0xFE, 125}); #endif
  #ifdef DIMER11 setStatus(DIMER2, {0xFE, 125}); #endif
  #ifdef DIMER13 setStatus(DIMER3, {0xFE, 125}); #endif
  #ifdef DIMER14 setStatus(DIMER4, {0xFE, 125}); #endif
  #ifdef DIMER15 setStatus(DIMER5, {0xFE, 125}); #endif
  #ifdef DIMER16 setStatus(DIMER6, {0xFE, 125}); #endif
  #ifdef DIMER17 setStatus(DIMER7, {0xFE, 125}); #endif
  #ifdef DIMER18 setStatus(DIMER8, {0xFE, 125}); #endif
  #ifdef DIMER19 setStatus(DIMER9, {0xFE, 125}); #endif
}