#include "mysyslog.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <time.h>
#include <syslog.h>

static mysyslog_driver_t* driver = NULL;

void
_mysyslog(const char* msg, mysyslog_level_t level, int driver_idx, int format, const char* path) {
	if (driver_idx < 0 || driver_idx >= 2) {
		// Invalid driver index
		return;
	}

	if (!driver) {
		// Load the driver dynamically
		char* driver_path = (driver_idx == 0) ? "libmysyslog-text.so" : "libmysyslog-json.so";
		void* handle = dlopen(driver_path, RTLD_LAZY);
		if (!handle) {
			// Failed to load the driver
			return;
		}

		dlerror(); // Clear any previous errors

		void (*init_func)(void) = (void (*)(void))dlsym(handle, "init");
		char* dlsym_error = dlerror();
		if (dlsym_error) {
			// Failed to get the init function
			dlclose(handle);
			return;
		}

		init_func();
		driver = (mysyslog_driver_t*)dlsym(handle, "driver");
		dlsym_error = dlerror();
		if (dlsym_error) {
			// Failed to get the driver struct
			dlclose(handle);
			return;
		}
	}

	if (driver && driver->log) {
		driver->log(msg, level, path);
	}
}

void
register_driver(mysyslog_driver_t* driver_ptr) {
	driver = driver_ptr;
}
