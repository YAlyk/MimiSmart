/*
{
      desc:"Тест IRT",
      name:"Тест IRT",
      tag:"item",
      selectArea:true,
      vars:[
            {name:"IRT", type:"devices-list",filter:["ir-transmitter"], required:true,  desc:"ИК-передатчик"},
      ]
}
*/

void vol(){
    u8 masOff[] = {0x1964020102004206011060000018FE2E30D312183D1C18D61230D512183E1C18D61218D61218D71218D71218D61230D412303D1C183F1C18D71200028A64};
    setStatus(IRT, &masOff);
}

V-ID/V-ADDR{
      if((opt(0)&1)==0){
            u8 masOff[] = {0x1964020102004206011060000018FE2E30D312183D1C18D61230D512183E1C18D61218D61218D71218D71218D61230D412303D1C183F1C18D71200028A64};
            setStatus(IRT, &masOff);
            delayedCall(vol, 1);
            delayedCall(vol, 2);
            delayedCall(vol, 3);
            delayedCall(vol, 4);
      } else {
            u8 masOff[] = {0x1964020102004206011060000018FE2E30D312183D1C18D61230D512183E1C18D61218D61218D71218D71218D61230D412303D1C183F1C18D71200028A64};
            setStatus(IRT, &masOff);
            delayedCall(vol, 1);
            delayedCall(vol, 2);
            delayedCall(vol, 3);
            delayedCall(vol, 4);
      }
}

