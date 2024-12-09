#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <json-c/json.h>
#include "json_driver.h"

void log_to_json(const char* msg, int level, const char* process) {
    json_object *jobj = json_object_new_object();
    json_object *jtime = json_object_new_string(ctime(&(time_t){time(NULL)}));
    json_object *jlevel = json_object_new_string(log_level_to_string(level));
    json_object *jprocess = json_object_new_string(process);
    json_object *jmessage = json_object_new_string(msg);

    json_object_object_add(jobj, "timestamp", jtime);
    json_object_object_add(jobj, "log_level", jlevel);
    json_object_object_add(jobj, "process", jprocess);
    json_object_object_add(jobj, "message", jmessage);

    printf("%s\n", json_object_to_json_string(jobj));
    json_object_put(jobj); // Освобождаем память
}
