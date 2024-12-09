#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "mysyslog.h"

volatile sig_atomic_t keep_running = 1;

void int_handler(int dummy) {
    keep_running = 0;
}

int main() {
    signal(SIGINT, int_handler);
    while (keep_running) {
        mysyslog("Daemon running", INFO, 0, 0, "log.txt");
        sleep(5); // Запись каждые 5 секунд
    }
    return EXIT_SUCCESS;
}
