/*
{
  desc:"насос rhx и батареи",
  tag:"item",
  selectArea:true,
  vars:[
    {name:"N01",type:"devices-list",required:true, filter:["lamp"],descWidth:250, desc:"насос/канал"},
    {name:"L01",type:"devices-list",required:true, filter:["valve-heating"],descWidth:250,desc:"отопление/ТП 1"},
    {name:"L02",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 2"},
    {name:"L03",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 3"},
    {name:"L04",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 4"},
    {name:"L05",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 5"},
    {name:"L06",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 6"},
    {name:"L07",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 7"},
    {name:"L08",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 8"},
    {name:"L09",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 9"},
    {name:"L10",type:"devices-list",required:false, filter:["valve-heating"],descWidth:250, desc:"отопление/ТП 10"},
 ]
}
*/

V-ID/L01, #ifdef L02 L02, #endif 
#ifdef L03 L03, #endif 
#ifdef L04 L04, #endif 
#ifdef L05 L05, #endif 
#ifdef L06 L06, #endif 
#ifdef L07 L07, #endif 
#ifdef L08 L08, #endif 
#ifdef L09 L09, #endif 
#ifdef L10 L10, #endif 
{  
  if ([V-ADDR.0]==1)
  {
    if (opt(0)==1 && [N01.0]==0) //если какое-то отопление/ТП вкл, а насос выкл, то вкл насос
    {
      setStatus(N01, 1);
    } else if ([L01.0] #ifdef L02 || [L02.0] #endif
#ifdef L03 || [L03.0] #endif //если хоть одно отпление вкл
#ifdef L04 || [L04.0] #endif
#ifdef L05 || [L05.0] #endif
#ifdef L06 || [L06.0] #endif
#ifdef L07 || [L07.0] #endif
#ifdef L08 || [L08.0] #endif
#ifdef L09 || [L09.0] #endif
#ifdef L10 || [L10.0] #endif)
    {
      setStatus(N01, 1); //то вкл насос
    } else setStatus(N01, 0); //иначе выкл
  }
}

V-ID/N01
{
  if (opt(0)==1) //если скрипт включили
  {
    //проверяем что хоть 1 отовление вкл
    if ([L01.0] #ifdef L02 || [L02.0] #endif
#ifdef L03 || [L03.0] #endif
#ifdef L04 || [L04.0] #endif
#ifdef L05 || [L05.0] #endif
#ifdef L06 || [L06.0] #endif
#ifdef L07 || [L07.0] #endif
#ifdef L08 || [L08.0] #endif
#ifdef L09 || [L09.0] #endif
#ifdef L10 || [L10.0] #endif) {
      setStatus(N01, 1); //если да вкл насос
  } else setStatus(N01, 0); //если нет выкл насос
}
}

