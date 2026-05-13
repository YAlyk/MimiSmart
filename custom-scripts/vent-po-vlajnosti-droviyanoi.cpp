/*
{
desc:"вента по влажности",
tag:"import-script",
selectArea:true,

vars:[
{name:"K00",type:"devices-list",required:true,width:800,filter:["conditioner"],desc:"Вентиляция",
{name:"S00",type:"devices-list",required:true,width:800,filter:["script"],desc:"Ручной режим",
{name:"D0",type:"devices-list",required:true,width:1000,filter:["humidity-sensor"],desc:"Датчик 0",descWidth:100},
]
}
*/

u8 kond[5];

V-ID/s:10
{
    if ([S00.0]==1)
    {
        u8 res = timeInRange(0:00-00:30);
        if(res != 0)
        {
            getStatus(K00, &kond); 
            kond[0]=(1); 
            kond[4]=(1);
            setStatus(K00, &kond);
            srvError("включаем по влажности");
        }
        else
        {
            setStatus(K00, 0);
            srvError("выключили по времени по времени");
        }
    }
    else
    {
        setStatus(K00, 0);
    }

    u32 s1 = time();
    u32 s2 = time();
    u32 s3 = s2 - s1; 
    if (s3 >= 1800) && ([D0.1]>)
}