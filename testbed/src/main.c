#include "../../engine/src/core/logger.h"

int main(void) {

  KFATAL("test message: %f", 3.44f);
  KERROR("test message: %f", 3.44f);
  KWARN("test message: %f", 3.44f);
  KINFO("test message: %f", 3.44f);
  KDEBUG("test message: %f", 3.44f);
  KTRACE("test message: %f", 3.44f);

  return 0;
}
