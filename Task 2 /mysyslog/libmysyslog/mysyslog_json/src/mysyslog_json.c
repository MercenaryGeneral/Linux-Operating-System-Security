// src/mysyslog_json.c

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "mysyslog_json.h"

int log_json(const char* msg, int level, const char* process) {
    // Получаем текущее время
    time_t now = time(NULL);

    // Форматируем и выводим сообщение в формате JSON
    printf("{\"timestamp\":%ld,\"log_level\":\"%s\",\"process\":\"%s\",\"message\":\"%s\"}\n",
           now, log_level_to_string(level), process, msg);
    return 0;
}
