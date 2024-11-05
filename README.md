# This is Lecture task 1 and 2 for Operating System Security 
## Task condition:
### Task 1: 
1.       Разработать консольную утилиту на языке BASH, которая обрабатывает аргументы командной строки и выполняет следующие действия:
для аргументов -u и --users выводит перечень пользователей и их домашних директорий на экран, отсортированных по алфавиту,
для аргументов -p и --processes выводит перечень запущенных процессов, отсортированных по их идентификатору,
для аргументов -h и --help выводит справку с перечнем и описанием аргументов и останавливает работу,
для аргументов -l PATH и –log PATH замещает вывод на экран выводом в файл по заданному пути PATH,
для аргументов -e PATH и –errors PATH замещает вывод ошибок из потока stderr в файл по заданному пути PATH.
2.       Обработка аргументов командной строки должны производиться при  помощи механизмов getopt или getopts.

3.       Обработка каждого типа действия должна производится в отдельной функции.

4.       Программа должна проверять доступ к пути и выводить соответствующие сообщения об ошибках. При этом программа должна фильтровать или обрабатывать выводы в stderr используемых команд.

5.       Задание должно быть выложено на github.
### Task 2: 
1.     Зарегистрируйтесь на портале github.com. Создайте проект, в котором будут размещаться ваши практические задания.

2.     Настройте файл «.gitignore», чтобы из вашего локального репозитория не попадали лишние файлы. Описание структуры файла: https://git-scm.com/docs/gitignore. Пример содержания файла «.gitignore» для языка Си: https://github.com/github/gitignore/blob/main/C.gitignore

3.     Добавьте в корне проекта его описание в формате Marcdown. Описание языка разметки:https://guides.github.com/features/mastering-markdown/, https://www.markdownguide.org/.

4.     Ознакомиться с требованиями по оформлению исходных кодов на языке Си. Все реализованные программы в данном задании должны быть разработаны с учетом данных требований.

https://www.gnu.org/prep/standards/html_node/Writing-C.html
5.     Рассмотреть примеры создания библиотек и динамического вызова функций из них при помощи функций dlopen/dlsym/dlclose:

https://github.com/skuhl/sys-prog-examples/tree/master/linking-types-example
https://gist.github.com/tailriver/30bf0c943325330b7b6a
https://github.com/cirosantilli/cpp-cheat/blob/81ab30c55634db24216e89ada1e0f271cac074e7/shared-library/basic/dlopen.c
https://github.com/examplecode/dlopen-demo
https://tldp.org/HOWTO/C++-dlopen/thesolution.html#loadingfunctions
6.     Рассмотреть пример Makefile с комментариями по сборке проекта, состоящего из нескольких файлов: https://github.com/skuhl/sys-prog-examples/blob/master/make-example/Makefile

(При необходимости использовать большую инструкцию по созданию Makefile: https://github.com/vampy/Makefile)

7.     Рассмотреть пример применения getopt и getopt_long для разбора аргументов командной строки: https://gist.github.com/thaim/7895785

8.     Рассмотреть пример программы демона, который работает с разными системами управления процессами и обрабатывает сигналы: https://github.com/jirihnidek/daemon/blob/master/src/daemon.c

9.     Рассмотреть пример примитивной программы логирования: https://gist.github.com/fclairamb/7441750

10.     Рассмотреть пример программы логирования с использованием библиотеки json-c: https://github.com/briandowns/struCtured-logger

11.     Рассмотреть пример учебного проекта по созданию deb-пакета: https://github.com/gl0v4nnl/Deb-package-simple-example

12.     Ознакомиться с инструкцией по ОС AstraLinux по созданию репозитория: https://wiki.astralinux.ru/pages/viewpage.action?pageId=61575159

13.     Завести на портале github общий проект mysyslog с набором подпроектов внутри: libmysyslog, libmysyslog-text, libmysyslog-json, libmysyslog-client, libmysyslog-daemon.

14.  Разработать расширяемую библиотеку libmysyslog на языке Си, которая сможет выводить данные в журнал в разных форматах. В рамках библиотеки необходимо реализовать функцию, через которую другие программы смогут выводить данные в журнал:

int mysyslog(const char* msg, int level, int driver, int format, const char* path);
 Должны поддерживаться следующие уровни журналирования: DEBUG, INFO, WARN, ERROR, CRITICAL.

15.  Для библиотеки libmysyslog реализовать в виде подключаемого плагина 2 драйвера (libmysyslog-text, libmysyslog-json): вывод в журнал в виде строки с разделителем и вывод в журнал в виде json строки. Каждый драйвер должен быть отдельным проектом и собираться отдельно (в итоге иметь отдельный deb-пакет).

Структура журнала в текстовом формате:

timestamp log_level process message

Пример журнала в текстовом формате:

1439482969 ERROR example-app this is an error
Структура журнала в формате JSON:

{"timestamp": ..., "log_level": ..., "process": ..., "message": ...}
Пример журнала в формате JSON:

{"timestamp":1439482969,"log_level":"ERROR","process":"example-app","message":"this is an error"}
16.  Сделать тестовое приложение на языке Си mysyslog-client, которое использует библиотеку libmysyslog и позволяет в аргументах командной строки задавать выводимый через библиотеку libmysyslog текст, уровень записи журнала, используемый драйвер и формат и путь к файлу. Аргументы командной строки обрабатывать через getopt.

17.  Сделать тестовое приложение демон mysyslog-daemon, который автоматически запускается во время старта компьютера и постоянно выводит в лог данные с разным уровнем. Приложение настраивается при помощи конфигурационного файла /etc/mysyslog/mysyslog.cfg. В конфигурационном файле задается: путь, формат и драйвер. Демон должен корректно обрабатывать получаемые сигналы и должен запускаться и останавливаться через systemctl.

18.  Все программы должны собираться при помощи Makefile, где обязательно должны быть добавлены следующие секции:

all – собирает все цели;
clean – удаляет все временные и объекты файлы, создаваемые при компиляции, исходные тексты должны приводится к изначальному виду;
deb – собирает deb-пакет для программы.
19.  Каждому модулю (программе и библиотеки) внутри подпроекта должен быть сделан отдельный файл readme.md на языке Markdown с описанием правил сборки и использования данного модуля.

20.  Для всех программ и библиотек должен создаваться deb-пакеты, которые зависят друг от друга. Кроме того, сделать метапакет mysyslog-meta, который устанавливает все пакеты (по зависимостям) сразу.

21.  Создать общий Makefile, который собирает все программы и формирует единый репозиторий, в нем должны быть реализованы цели для каждой из программ и библиотек, а также цель repo, которая формирует репозиторий.

22.  Сделать репозиторий из подготовленных deb-пакетов.

23.  Развернуть репозиторий на сервере. Настроить на клиенте доступ к репозиторию.

24.  Установить метапакет на клиенте. Настроить на клиенте работу демона.

25.  Проверить работу программ. Сделать отчет о работе программ mysyslog-client, mysyslog-daemon. 