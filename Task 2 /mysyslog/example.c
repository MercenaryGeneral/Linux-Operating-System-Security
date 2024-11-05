// example.c

#include <stdio.h>
#include "mysyslog.h"

int main() {
    // Пример записи в журнал
    mysyslog("This is a debug message", DEBUG, DRIVER_CONSOLE, TEXT, NULL);
    mysyslog("This is an info message", INFO, DRIVER_FILE, TEXT, "log.txt");
    mysyslog("This is an error message", ERROR, DRIVER_CONSOLE, JSON, NULL);
    return 0;
}
