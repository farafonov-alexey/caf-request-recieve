#include "interface.h"
#include "library.h"
#include <iostream>

using namespace std;
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_create() {
  auto &manager = library::instance().library_manager();
  manager.create();
}
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_destroy() {
  auto &manager = library::instance().library_manager();
  manager.destroy();
}
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_do_stuff(int param_id, uint value) {
  auto &manager = library::instance().library_manager();
  manager.do_stuff();
}