/*
{
  desc:"Увлажнитель и кондей",
  tag:"item",
  selectArea:true,
  name:"Климат",
  vars:[
  {name:"K00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
  {name:"K01",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
  {name:"K02",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Кондиционер",descWidth:100},
  {name:"Y00",type:"devices-list",required:false,width:800,filter:["conditioner"],desc:"Увлажнитель",descWidth:100},
  ]
}
*/

u8 kond[5];
u8 yvlaj[5];

V-ID/s:5
{
    if ([V-ADDR]==1)
    {
        getStatus(K00, &kond);
        getStatus(Y00, &yvlaj);
        if ([K00.0]==1 || [K01.0]==1 || [K02.0]==1)
        {
            //srvError("Включен кондей, вырубаем увлажнитель");
            //srvError(&kond);
            setStatus(Y00, 0);
        }
        // else
        // {
        //     srvError("Выключен кондей, врубаем увлажнитель");
        //     srvError(&kond);
        //     setStatus(Y00, 1);
        // }
        if ([Y00.0]==1)
        {
            setStatus(K00, 0);
            setStatus(K01, 0);
            setStatus(K02, 0);
        }
    }
}
