# Интеграция: Sony BRAVIA TV

Управление телевизором Sony BRAVIA через REST API по локальной сети.  
Используется аутентификация по Pre-Shared Key (PSK) через заголовок `X-Auth-PSK`.

> **Примечание:** Несмотря на папку `samsung-tv` (исторически), эти скрипты работают с **Sony BRAVIA**, не Samsung.

---

## Протокол

Sony BRAVIA предоставляет HTTP REST API, основанный на JSON-RPC.  
Запросы отправляются методом `POST` на эндпоинты вида `http://<TV_IP>/sony/<service>`.

**Аутентификация:** заголовок `X-Auth-PSK: <ключ>`  
**Порт:** 80 (HTTP)

### Основные эндпоинты

| Эндпоинт | Назначение |
|---|---|
| `/sony/system` | Питание, системные команды |
| `/sony/avContent` | Переключение источников входа |

---

## Настройка телевизора

1. `Настройки → Сеть → Настройка домашней сети → IP-управление → Включить`
2. `→ Аутентификация → Нормальный и Pre-Shared Key`
3. `→ Pre-Shared Key → задать ключ (например: 1111)`
4. `→ Удалённый запуск → Включить` (для включения из Standby)

---

## Скрипты

### 40.sh — Выключение телевизора
```bash
./40.sh
```
Отправляет команду `setPowerStatus` с `status: false`.  
Эндпоинт: `/sony/system`

---

### 41.sh — Включение телевизора
```bash
./41.sh
```
Отправляет команду `setPowerStatus` с `status: true`.  
Эндпоинт: `/sony/system`

> Для включения из состояния полного выключения может потребоваться **Wake-on-LAN**.  
> Из режима Standby включается через этот же API.

---

### 42.sh — Переключение на HDMI 3
```bash
./42.sh
```
Отправляет команду `setPlayContent` с URI `extInput:hdmi?port=3`.  
Эндпоинт: `/sony/avContent`

Для других HDMI-портов измени `port=3` на нужный номер.

---

## Конфигурация

Перед использованием отредактируй в каждом скрипте:

```bash
TV_IP="192.168.1.89"   # IP-адрес телевизора в вашей сети
PSK="1111"             # Pre-Shared Key, заданный в настройках ТВ
```

---

## Ручное тестирование

Проверить доступность API и включить телевизор можно прямо из терминала:

```bash
curl -X POST \
  -H "Content-Type: application/json; charset=UTF-8" \
  -H "X-Auth-PSK: 1111" \
  -d '{"method": "getPowerStatus", "params": [], "id": 1, "version": "1.0"}' \
  http://192.168.1.89/sony/system
```

---

## Документация

- [Sony BRAVIA REST API — Getting Started](https://pro-bravia.sony.net/develop/integrate/rest-api/spec/getting-started/)
- [Sony BRAVIA REST API — Полная спецификация](https://pro-bravia.sony.net/develop/integrate/rest-api/spec/index.html)
- [Неофициальная документация (Gist)](https://gist.github.com/kalleth/e10e8f3b8b7cb1bac21463b0073a65fb)
