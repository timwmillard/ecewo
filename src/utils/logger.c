#include <stdio.h>
#include <stdarg.h>

#include "ecewo.h"

static LogHandler log_handler = NULL;

#ifdef ECEWO_DEBUG
static LogLevel min_log_level = LOG_LEVEL_DEBUG;
#else
static LogLevel min_log_level = LOG_LEVEL_DEBUG;
#endif

void server_set_log_handler(LogHandler handler) {
    log_handler = handler;
}

void server_set_log_level(LogLevel min_level) {
    min_log_level = min_level;
}

void ecewo_log(LogLevel level, const char *file, int line,
               const char *fmt, ...) {
    if (level < min_log_level) return;

    va_list args;
    va_start(args, fmt);

    if (log_handler) {
        log_handler(level, file, line, fmt, args);
    } else {
        // Default: print to stderr
        const char *level_str[] = {"DEBUG", "INFO", "WARN", "ERROR"};
        fprintf(stderr, "[%s] %s:%d ", level_str[level], file, line);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
    }

    va_end(args);
}
