// src/mysyslog.c

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "mysyslog.h"

// Функция для получения строки уровня журналирования
const char* log_level_to_string(LogLevel level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARN: return "WARN";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

// Функция для записи в журнал
int mysyslog(const char* msg, LogLevel level, LogDriver driver, LogFormat format, const char* path) {
    // Получаем текущее время
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

    // Форматируем сообщение
    char log_message[256];
    if (format == TEXT) {
        snprintf(log_message, sizeof(log_message), "%s %s: %s\n", timestamp, log_level_to_string(level), msg);
    } else if (format == JSON) {
        snprintf(log_message, sizeof(log_message), "{\"timestamp\":\"%s\", \"log_level\":\"%s\", \"message\":\"%s\"}\n",
                 timestamp, log_level_to_string(level), msg);
    } else {
        return -1; // Неподдерживаемый формат
    }

    // Записываем сообщение в зависимости от драйвера
    if (driver == DRIVER_CONSOLE) {
        printf("%s", log_message);
    } else if (driver == DRIVER_FILE) {
        if (path == NULL) {
            return -1; // Путь не указан
        }
        FILE *file = fopen(path, "a");
        if (file == NULL) {
            return -1; // Ошибка открытия файла
        }
        fputs(log_message, file);
        fclose(file);
    } else {
        return -1; // Неподдерживаемый драйвер
    }

    return 0; // Успешно
}
