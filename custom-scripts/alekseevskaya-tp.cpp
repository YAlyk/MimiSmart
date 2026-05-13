/*
{
    desc:"Вытяжка от скрипта",
    tag:"import-script",
    selectArea:true,
    
    vars:[
{name:"V00",type:"devices-list",required:true,width:600,filter:["lamp"],desc:"ВЫТЯЖКА",descWidth:100},
{name:"S00",type:"devices-list",required:true,width:600,filter:["script"],desc:"скрипт",descWidth:100},
    ]
}
*/

V-ID/S00{
    if ([S00.0]==1){
        setStatus(V00, 1);
    }
    else{
        setStatus(V00, 0);
    }
}