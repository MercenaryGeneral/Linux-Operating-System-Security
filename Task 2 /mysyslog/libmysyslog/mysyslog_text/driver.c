#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "text_driver.h"

void log_to_text(const char* msg, int level, const char* process) {
    time_t now = time(NULL);
    char* timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Удаляем символ новой строки

    printf("%s %s %s\n", timestamp, log_level_to_string(level), msg);
}
