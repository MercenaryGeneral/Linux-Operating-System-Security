#ifndef JSON_DRIVER_H
#define JSON_DRIVER_H

#include "mysyslog.h"

void log_to_json(const char* msg, int level, const char* process);

#endif // JSON_DRIVER_H
