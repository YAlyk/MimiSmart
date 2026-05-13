/*
{
desc:"вента по таймеру",
tag:"item",
selectArea:true,

vars:[
{name:"K00",type:"devices-list",required:true,width:800,filter:["conditioner"],desc:"Вентиляция"},
{name:"S00",type:"devices-list",required:true,width:800,filter:["script"],desc:"Ручной режим"},
{name:"T1", type:"number", defaultValue:10, min:1, max:180, required:true, desc:"Время до выключения мин"},
]
}
*/

u8 kond[5];

void OFFVent()
{
    getStatus(K00, &kond); 
        kond[0]=(0); 
        kond[4]=(3);
        setStatus(K00, &kond);
}

void OFFItem()
{
    setStatus(V-ADDR,0);
}

V-ID/V-ADDR
{
    if (opt(0)==1)
    {
        delayedCall(OFFItem, 2);
        getStatus(K00, &kond); 
        kond[0]=(1); 
        kond[4]=(3);
        setStatus(K00, &kond);
        delayedCall(OFFVent, T1);
        
    }
}