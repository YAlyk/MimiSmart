/*
{
desc:"вента по времени",
tag:"import-script",
selectArea:true,

vars:[
{name:"K00",type:"devices-list",required:true,width:800,filter:["conditioner"],desc:"Вентиляция"},
{name:"S00",type:"devices-list",required:true,width:800,filter:["script"],desc:"Ручной режим"},
]
}
*/

u8 kond[5];

V-ID/s:10
{
    if ([S00.0]==1)
    {
        u8 res0 = timeInRange(00:00-00:30);
        u8 res1 = timeInRange(03:00-03:30);
        u8 res2 = timeInRange(06:00-06:30);
        u8 res3 = timeInRange(09:00-09:30);
        u8 res4 = timeInRange(12:00-12:30);
        u8 res5 = timeInRange(15:00-15:30);
        u8 res6 = timeInRange(18:00-18:30);
        u8 res7 = timeInRange(21:00-21:30);
        if(res0 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        if(res1 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        if(res2 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        if(res3 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        if(res4 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        if(res5 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        if(res6 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        if(res7 != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(0);
            setStatus(K00, &kond);
            //srvError("включаем по времени");
        }
        else
        {
            setStatus(K00, 0);
            //srvError("выключили по времени по времени");
        }
    }
    else
    {
        setStatus(K00, 0);
    }
}