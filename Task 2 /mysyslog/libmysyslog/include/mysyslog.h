// include/mysyslog.h

#ifndef MYSYSLOG_H
#define MYSYSLOG_H

// Уровни журналирования
typedef enum {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
} LogLevel;

// Форматы вывода
typedef enum {
    TEXT,
    JSON
} LogFormat;

// Драйверы вывода
typedef enum {
    DRIVER_CONSOLE,
    DRIVER_FILE
} LogDriver;

// Функция для записи в журнал
int mysyslog(const char* msg, LogLevel level, LogDriver driver, LogFormat format, const char* path);

#endif // MYSYSLOG_H
