/*
{
	desc:"Кастом вентиляция казак",
	tag:"import-script",
	selectArea:true,
	
	vars:[
    {name:"V0",type:"devices-list",required:true,width:1000,filter:["door-sensor"],desc:"Вытяжка кухни",descWidth:100},
    {name:"L0",type:"devices-list",required:true,width:1000,filter:["lamp","script"],desc:"Установка",descWidth:100},
    {name:"SPOT",type:"devices-list",required:true,width:1000,filter:["lamp","script"],desc:"Свет",descWidth:100},
	]
}
*/

V-ID/s:5
{
    // Проверка времени: ночь (23:01-11:01) или день (11:01-23:01)
    u8 is_night = timeInRange(23:01-11:01);

    // Логика для ночного времени
    if (is_night != 0) {
        if ([V0.0] == 0) { // Геркон активирован
            setStatus(L0, 0); // Включить на гостиную
            srvError("Ночь: геркон активирован, вкл на гостиную");
        } else if ([SPOT.0] == 1) { // Споты включены
            setStatus(L0, 1); // Включить на спальню
            srvError("Ночь: споты включены, вкл на спальню");
        } else { // Геркон и споты выключены
            setStatus(L0, 1); // Включить на спальню (по умолчанию ночью)
            srvError("Ночь: геркон и споты выключены, вкл на спальню");
        }
    }
    // Логика для дневного времени
    else {
        if ([V0.0] == 0) { // Геркон активирован
            setStatus(L0, 0); // Включить на гостиную
            srvError("День: геркон активирован, вкл на гостиную");
        } else if ([SPOT.0] == 1) { // Споты включены
            setStatus(L0, 1); // Включить на спальню
            srvError("День: споты включены, вкл на спальню");
        } else { // Геркон и споты выключены
            setStatus(L0, 0); // Включить на гостиную (по умолчанию днем)
            srvError("День: геркон и споты выключены, вкл на гостиную");
        }
    }
}