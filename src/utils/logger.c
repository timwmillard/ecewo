#include <stdio.h>
#include <stdarg.h>

#include "ecewo.h"

static LogHandler ecewo_log_handler = NULL;
static LogLevel ecewo_min_log_level = LOG_LEVEL_INFO;

void ecewo_set_log_handler(LogHandler handler) {
    ecewo_log_handler = handler;
}

void ecewo_set_log_level(LogLevel min_level) {
    ecewo_min_log_level = min_level;
}

void ecewo_log(LogLevel level, const char *file, int line,
               const char *fmt, ...) {
    if (level < ecewo_min_log_level) return;

    va_list args;
    va_start(args, fmt);

    if (ecewo_log_handler) {
        ecewo_log_handler(level, file, line, fmt, args);
    } else {
        // Default: print to stderr
        const char *level_str[] = {"DEBUG", "INFO", "WARN", "ERROR"};
        fprintf(stderr, "[%s] %s:%d ", level_str[level], file, line);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
    }

    va_end(args);
}
