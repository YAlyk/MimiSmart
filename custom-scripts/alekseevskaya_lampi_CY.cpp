/*
{
  desc:"Мастер слейв лампы (фартук от света)",
  tag:"import-script",
  selectArea:true,
  vars:[
		{name:"D",type:"number",required:true,defaultValue:15,min:0,max:100,desc:"Порог яркости",descWidth:350},
        {name:"M1",type:"devices-list",required:true,width:200,filter:["dimer-lamp"],desc:"мастер 1"},
        {name:"S1",type:"devices-list",required:true,width:200,filter:["lamp","dimer-lamp"],desc:"слейв 1"},
  ]
}
*/

V-ID/M1{
    if (([M1.0]==1) && ([M1.1]>=(D*250/100))){
        setStatus(S1,1);
    }
    else{
       setStatus(S1,0); 
    }
}