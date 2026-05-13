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


//
V-ID/V-ADDR{
      if((opt(0)&1)==0){
            u8 masOff[] = {0x196401000200A006080E0F1D0B02};
            setStatus(IRT, &masOff);
            setStatus(IRT, &masOff);
            setStatus(IRT, &masOff);
            setStatus(IRT, &masOff);
            setStatus(IRT, &masOff);
      } else {
            u8 masOn[] = {0x196401000200A006080E0F1D0B02};
            setStatus(IRT, &masOn);
            setStatus(IRT, &masOn);
            setStatus(IRT, &masOn);
            setStatus(IRT, &masOn);
            setStatus(IRT, &masOn);
      }
}

