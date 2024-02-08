#include "../../engine/src/core/application.h"
#include "../../engine/src/core/logger.h"
#include <stdio.h>

int main(void) {

  Application app;

  if (app_init(&app) != TRUE) {
    return -1;
  }

  app_run(&app);
  app_cleanup(&app);

  return 0;
}
