## Дисклеймер

Это **неофициальный** репозиторий.  
Все скрипты написаны в частном порядке и предоставляются **«как есть»**, без каких-либо гарантий.  
Автор не несёт ответственности за любые последствия использования материалов из этого репозитория.

---
# Integrations

Коллекция кастом-скриптов и интеграций для системы умного дома.  
Скрипты написаны на Bash, PHP и внутреннем языке Mimi Logic.


---

## Структура репозитория

```
├── custom-scripts/      # Кастомные скрипты на Mimi Logic под конкретные объекты и ТЗ
│   ├── (свет, климат, шторы, охрана, вентиляция, уведомления и др.)
│   └── README.md
│
└── integrations/        # Bash/PHP-скрипты для интеграции внешнего AV-оборудования
    ├── samsung-tv/          # Sony BRAVIA — управление по REST API (HTTP + PSK)
    │   ├── 40.sh            # Выключение телевизора
    │   ├── 41.sh            # Включение телевизора
    │   └── 42.sh            # Переключение на HDMI 3
    │
    ├── denon-receiver/      # Ресивер Denon AVR — управление по Telnet (порт 23)
    │   ├── 90.sh            # Включение ресивера (PWON)
    │   ├── 91.sh            # Выключение ресивера (PWSTANDBY)
    │   ├── 92.sh            # Источник: TV (SITV)
    │   ├── 93.sh            # Источник: Game (SIGAME)
    │   ├── 94.sh            # Источник: Media Player (SIMPLAY)
    │   └── 95.sh            # Отправка команды через GNU screen/Telnet (PHP)
    │
    ├── jvc-projector/       # Проектор JVC — управление бинарными командами по TCP
    │   └── 21.sh            # Включение проектора
    │
    └── openweathermap/      # Погода OpenWeatherMap → виртуальные сенсоры MimiSmart
        └── 96.sh            # Получение погоды и отправка в MimiSmart (PHP)
```

---

## Кастомные скрипты

Скрипты на внутреннем языке Mimi Logic, написанные под конкретные объекты и ТЗ.  
Покрывают свет, климат, вентиляцию, шторы, охрану, уведомления и другие сценарии.

→ [Полный список с описаниями](custom-scripts/README.md)

---

## Интеграции внешнего оборудования

| Устройство | Протокол | Порт | Скрипты |
|---|---|---|---|
| [Sony BRAVIA TV](integrations/samsung-tv/README.md) | HTTP REST API + PSK | 80 | 40, 41, 42 |
| [Denon AVR Receiver](integrations/denon-receiver/README.md) | Telnet / PHP | 23 | 90–96 |
| [JVC Projector](integrations/jvc-projector/README.md) | TCP Binary | 4661 | 21 |
| [OpenWeatherMap](integrations/openweathermap/README.md) | HTTP REST API | 443 | 96 |

---

## Требования

- **Bash** — для `.sh` скриптов
- **curl** — для Sony BRAVIA HTTP-запросов
- **netcat (nc)** — для Denon Telnet-команд
- **PHP** — для скриптов 95.sh (Denon) и 96.sh (OpenWeatherMap)
- **GNU screen** — для 95.sh (сессия Telnet в screen)
- Все устройства должны находиться в **одной локальной сети** с сервером MimiSmart

---

## Быстрый старт

1. Склонируй репозиторий:
   ```bash
   git clone https://github.com/<your-username>/mimismart-integrations.git
   ```
2. Задай права на выполнение:
   ```bash
   chmod +x integrations/**/*.sh
   ```
3. Отредактируй IP-адреса устройств в скриптах под свою сеть.
4. Подключи скрипты к соответствующим номерам команд в MimiSmart.

Подробности — в README каждой интеграции.

---

## Документация по протоколам

- [Sony BRAVIA REST API](https://pro-bravia.sony.net/develop/integrate/rest-api/spec/)
- [Denon AVR Control Protocol (PDF)](https://assets.denon.com/documentmaster/us/avr2113ci_avr1913_protocol_v04.pdf)
- [JVC D-ILA LAN Control Guide (PDF)](https://support.jvc.com/consumer/support/documents/DILAremoteControlGuide.pdf)
- [OpenWeatherMap API](https://openweathermap.org/api)



## Лицензия

MIT — используй свободно.
