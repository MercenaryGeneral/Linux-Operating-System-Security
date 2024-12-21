# mysyslog-client

## Описание
Клиентское приложение для использования библиотеки `libmysyslog` и журналирования сообщений.

## Сборка
Используйте команду `make` для сборки клиента.

```bash
make
```
 
## Установка
Для установки deb-пакета выполните:

```
make deb
```

## Использование
Запустите клиент с параметрами:
```
./mysyslog-client -m "Your message" -l <level> -d <driver> -f <format> -p <path>
```
Пример:
```
./mysyslog-client -m "Hello, World!" -l 1 -d 0 -f 0 -p "log.txt"
