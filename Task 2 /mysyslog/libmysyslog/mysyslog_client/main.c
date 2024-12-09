#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "Task 2 /mysyslog/libmysyslog/mysyslog.h"

static const struct option long_options[] = {
	{ "message", required_argument, 0, 'm' },
	{ "level", required_argument, 0, 'l' },
	{ "driver", required_argument, 0, 'd' },
	{ "format", required_argument, 0, 'f' },
	{ "path", required_argument, 0, 'p' },
	{ 0, 0, 0, 0 }
};

void
usage(const char* program) {
	printf("Usage: %s [options]\n", program);
	printf("\t--message, -m  Message to log\n");
	printf("\t--level, -l    Log level (DEBUG, INFO, WARN, ERROR, CRITICAL)\n");
	printf("\t--driver, -d   Driver to use (text, json)\n");
	printf("\t--format, -f   Format to use (text, json)\n");
	printf("\t--path, -p     Log file path\n");
	exit(EXIT_FAILURE);
}

int
main(int argc, char** argv) {
	const char* msg = NULL;
	mysyslog_level_t level = MYSYSLOG_INFO;
	int driver_idx = 0;
	int format_idx = 0;
	const char* path = NULL;
	int opt;

	while ((opt = getopt_long(argc, argv, "m:l:d:f:p:", long_options, NULL)) != -1) {
		switch (opt) {
		case 'm':
			msg = optarg;
			break;
		case 'l':
			if (strcmp(optarg, "DEBUG") == 0)
				level = MYSYSLOG_DEBUG;
			else if (strcmp(optarg, "INFO") == 0)
				level = MYSYSLOG_INFO;
			else if (strcmp(optarg, "WARN") == 0)
				level = MYSYSLOG_WARN;
			else if (strcmp(optarg, "ERROR") == 0)
				level = MYSYSLOG_ERROR;
			else if (strcmp(optarg, "CRITICAL") == 0)
				level = MYSYSLOG_CRITICAL;
			else
				usage(argv[0]);
			break;
		case 'd':
			if (strcmp(optarg, "text") == 0)
				driver_idx = 0;
			else if (strcmp(optarg, "json") == 0)
				driver_idx = 1;
			else
				usage(argv[0]);
			break;
		case 'f':
			if (strcmp(optarg, "text") == 0)
				format_idx = 0;
			else if (strcmp(optarg, "json") == 0)
				format_idx = 1;
			else
				usage(argv[0]);
			break;
		case 'p':
			path = optarg;
			break;
		default:
			usage(argv[0]);
		}
	}

	if (!msg || !path)
		usage(argv[0]);

	mysyslog(msg, level, driver_idx, format_idx, path);

	return 0;
}
