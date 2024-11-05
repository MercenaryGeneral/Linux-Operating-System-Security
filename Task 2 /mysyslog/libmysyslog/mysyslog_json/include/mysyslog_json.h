// include/mysyslog_json.h

#ifndef MYSYSLOG_JSON_H
#define MYSYSLOG_JSON_H

#include "mysyslog.h"

// Функция для записи в JSON журнал
int log_json(const char* msg, int level, const char* process);

#endif // MYSYSLOG_JSON_H
