#ifndef ECEWO_LOGGER_H
#define ECEWO_LOGGER_H

#include "ecewo.h"

void ecewo_log(LogLevel level, const char *file, int line,
               const char *fmt, ...);

#define LOG_INFO(fmt, ...) \
    ecewo_log(LOG_LEVEL_INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_DEBUG(fmt, ...) \
  ecewo_log(LOG_LEVEL_DEBUG, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
  ecewo_log(LOG_LEVEL_ERROR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif
