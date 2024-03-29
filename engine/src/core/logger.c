#include "logger.h"

// TODO: temp
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

b8 initialize_logging() {
  // TODO: create log file
  return TRUE;
}
void shutdown_logging() {
  // TODO: cleanup loggin/write queued enteries
}

KAPI void log_output(log_level level, const char *message, ...) {
  const char *level_strings[6] = {"[FATAL]:  ", "[ERROR]:  ",  "[WARN]:  ",
                                  "[INFO]:   ", "[DEBUG]:   ", "[TRACE]:  "};
  // b8 is_error = level < 2;

  // technically imposes a 32k character limit

  char out_message[32000];
  memset(out_message, 0, sizeof(out_message));

  // Format original message
  va_list arg_ptr;
  va_start(arg_ptr, message);
  vsnprintf(out_message, 32000, message, arg_ptr);
  va_end(arg_ptr);

  char out_message2[32000];
  sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

  printf("%s", out_message2);
}
