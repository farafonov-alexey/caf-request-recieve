#include "library/interface.h"
#include <iostream>
int main() {
  lib_create();
  for (int i = 0; i < 10; i++) {
    lib_do_stuff(1, 2);
  }
  lib_destroy();
  return 0;
}