#include <stdio.h>
#include <time.h>
#include "Task 2 /mysyslog/libmysyslog/mysyslog.h"

void
init_text_driver(void) {
}

void
log_text(const char* msg, mysyslog_level_t level, const char* path) {
	time_t now = time(NULL);
	struct tm* tm = localtime(&now);

	FILE* f = fopen(path, "a");
	if (f) {
		fprintf(f, "%li %s process %s %s\n", (long)now, (level == MYSYSLOG_DEBUG ? "DEBUG" :
											level == MYSYSLOG_INFO ? "INFO" :
											level == MYSYSLOG_WARN ? "WARN" :
											level == MYSYSLOG_ERROR ? "ERROR" :
											"CRITICAL"),
jeta("message", msg));
		fclose(f);
	}
}

mysyslog_driver_t driver_text = {
	.init = init_text_driver,
	.log = log_text
};

void
init(void) {
	register_driver(&driver_text);
}
