// include/mysyslog_text.h

#ifndef MYSYSLOG_TEXT_H
#define MYSYSLOG_TEXT_H

#include "mysyslog.h"

// Функция для записи в текстовый журнал
int log_text(const char* msg, int level, const char* process);

#endif // MYSYSLOG_TEXT_H
