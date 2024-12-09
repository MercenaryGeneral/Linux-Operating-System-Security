#ifndef MYSYSLOG_H
#define MYSYSLOG_H

#include <stdint.h>

typedef enum {
	MYSYSLOG_DEBUG,
	MYSYSLOG_INFO,
	MYSYSLOG_WARN,
	MYSYSLOG_ERROR,
	MYSYSLOG_CRITICAL
} mysyslog_level_t;

typedef struct {
	void (*init)(void);
	void (*log)(const char* msg, mysyslog_level_t level, const char* path);
} mysyslog_driver_t;

#define mysyslog(msg, level, driver, format, path) \
	extern void _mysyslog(const char* msg, mysyslog_level_t level, int driver, int format, const char* path); \
	_mysyslog(msg, level, driver, format, path)

#endif // MYSYSLOG_H
