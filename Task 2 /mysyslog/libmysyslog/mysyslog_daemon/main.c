#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <json-c/json.h>
#include "../libmysyslog/mysyslog.h"

void
daemonize(void) {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	if (setsid() == -1) {
		perror("Failed to create a new session");
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void
read_config(const char* path) {
	// Implement JSON parsing of the config file to get path, format, and driver
}

int
main(int argc, char** argv) {
	daemonize();

	read_config("/etc/mysyslog/mysyslog.cfg");

	return 0;
}
