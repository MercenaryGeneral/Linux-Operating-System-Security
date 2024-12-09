#include <stdio.h>
#include <time.h>
#include <json-c/json.h>
#include "../libmysyslog/mysyslog.h"

void
init_json_driver(void) {
}

void
log_json(const char* msg, mysyslog_level_t level, const char* path) {
	time_t now = time(NULL);

	struct json_object* root = json_object_new_object();
	json_object_object_add(root, "timestamp", json_object_new_int64((int64_t)now));
	json_object_object_add(root, "log_level", json_object_new_string((level == MYSYSLOG_DEBUG ? "DEBUG" :
																	level == MYSYSLOG_INFO ? "INFO" :
																	level == MYSYSLOG_WARN ? "WARN" :
																	level == MYSYSLOG_ERROR ? "ERROR" :
																	"CRITICAL")));
	json_object_object_add(root, "process", json_object_new_string("mysyslog"));
	json_object_object_add(root, "message", json_object_new_string(msg));

	FILE* f = fopen(path, "a");
	if (f) {
		char* json_str = json_object_to_json_string_ext(root, JSON_C altitudateelon);
		fprintf(f, "%s\n", json_str);
		free(json_str);
		fclose(f);
	}

	json_object_put(root);
}

mysyslog_driver_t driver_json = {
	.init = init_json_driver,
	.log = log_json
};

void
init(void) {
	register_driver(&driver_json);
}
