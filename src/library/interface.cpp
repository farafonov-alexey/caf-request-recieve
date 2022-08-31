#include "interface.h"
#include "library.h"
#include <iostream>

using namespace std;
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_create() {
  cout << "lib_create thread: " << std::this_thread::get_id() << endl;
  library::instance().do_task([](library_manager_base &lib) {
    cout << "lib_create thread do_task: " << std::this_thread::get_id() << endl;
    lib.create();
    return 1;
  });
  cout << "lib_create task_res: " << library::instance().task_result() << endl;
}
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_destroy() {
  cout << "lib_destroy thread: " << std::this_thread::get_id() << endl;
  library::instance().do_task([](library_manager_base &lib) {
    cout << "lib_destroy thread do_task: " << std::this_thread::get_id()
         << endl;
    lib.destroy();
    return 2;
  });
  cout << "lib_destroy task_res: " << library::instance().task_result() << endl;
}
LIB_SHARED_EXPORT void LIB_SHARED_CCA lib_do_stuff(int param_id, uint value) {
  cout << "lib_do_stuff thread: " << std::this_thread::get_id() << endl;
  library::instance().do_task([](library_manager_base &lib) {
    cout << "lib_do_stuff thread do_task: " << std::this_thread::get_id()
         << endl;
    lib.do_stuff();
    return 3;
  });
  cout << "lib_do_stuff task_res: " << library::instance().task_result()
       << endl;
}