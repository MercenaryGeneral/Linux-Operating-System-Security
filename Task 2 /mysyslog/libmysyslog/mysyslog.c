#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mysyslog.h"

const char* log_level_to_string(int level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARN: return "WARN";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    // Получаем текущее время
    time_t now = time(NULL);
    char* timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Удаляем символ новой строки

    // Формируем строку лога
    char log_entry[256];
    snprintf(log_entry, sizeof(log_entry), "%s %s %s", timestamp, log_level_to_string(level), msg);

    // Записываем в файл
    FILE* file = fopen(path, "a");
    if (!file) {
        perror("Unable to open log file");
        return -1;
    }

    fprintf(file, "%s\n", log_entry);
    fclose(file);
    return 0;
}
