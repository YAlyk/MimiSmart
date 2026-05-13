/*
{
  desc:"Костыль для сири и схем",
  tag:"item",
  selectArea:true,
  vars:[
        {name:"M1",type:"devices-list",required:true,width:200,filter:["script"],desc:"Элемент который интегрируем:"},
  ]
}
*/

V-ID/V-ADDR{
    if ([V-ADDR.0]==1)
    {
        setStatus(M1, 1);
    }
    else{
        setStatus(M1, 0);
    }
}