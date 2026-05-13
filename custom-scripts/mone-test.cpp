/*{
  desc:"гсу монэ",  
  ttag:"item",
  selectArea:true,
  vars:[
    {name:"DIM",type:"devices-list",required:true,filter:["dimer-lamp"],desc:"Диммер на 100%",descWidth:300,width:300},
    {name:"AVTO",type:"devices-list",required:true,filter:["script"],desc:"скрипт для авто",descWidth:300,width:300},
    ]
}*/


// Проверка времени для каждого элемента
V-ID/V-ADDR {
    if (([V-ADDR.0]&1)==1){
        setStatus(DIM, {0xFE, 250});
        setStatus(AVTO, 0);
    }
    else{
        setStatus(AVTO, 1);
    }
}
