// src/mysyslog_text.c

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "mysyslog_text.h"

int log_text(const char* msg, int level, const char* process) {
    // Получаем текущее время
    time_t now = time(NULL);
    char timestamp[20];
    snprintf(timestamp, sizeof(timestamp), "%ld", now);

    // Форматируем и выводим сообщение
    printf("%s %s %s %s\n", timestamp, log_level_to_string(level), process, msg);
    return 0;
}
