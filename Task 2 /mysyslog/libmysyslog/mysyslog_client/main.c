#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "mysyslog.h"

void print_usage() {
    printf("Usage: mysyslog-client -m <message> -l <level> -d <driver> -f <format> -p <path>\n");
}

int main(int argc, char *argv[]) {
    char *msg = NULL;
    int level = INFO;
    int driver = 0; // 0 - текст, 1 - JSON
    int format = 0; // 0 - текст, 1 - JSON
    char *path = "log.txt"; // Путь по умолчанию

    int opt;
    while ((opt = getopt(argc, argv, "m:l:d:f:p:")) != -1) {
        switch (opt) {
            case 'm':
                msg = optarg;
                break;
            case 'l':
                level = atoi(optarg);
                break;
            case 'd':
                driver = atoi(optarg);
                break;
            case 'f':
                format = atoi(optarg);
                break;
            case 'p':
                path = optarg;
                break;
            default:
                print_usage();
                return EXIT_FAILURE;
        }
    }

    if (msg == NULL) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Здесь вызовите mysyslog с соответствующими параметрами
    mysyslog(msg, level, driver, format, path);
    return EXIT_SUCCESS;
}
