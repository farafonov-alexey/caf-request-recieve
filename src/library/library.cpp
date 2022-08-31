#include "library.h"
#include "atoms.h"
#include "caf_system.h"
#include "library_manager.h"
#include "reciever_actor.h"
#include "sender_actor.h"
#include <iostream>
#include <memory>

using namespace std;
using namespace caf;
using namespace fruit;
library::library(token) {
  cout << "constructed" << std::endl;
  worker = std::thread([this] {
    init_global_meta_objects<caf::id_block::library>();
    core::init_global_meta_objects();
    injector_ =
        make_unique<fruit::Injector<library_manager_base>>(get_injector);

    library_manager_base &lib = injector_->get<library_manager_base &>();
    //
    task tsk;
    // dequeue and process tasks
    while (boost::fibers::channel_op_status::closed != ch.pop(tsk)) {
      ch_res.push(tsk(lib));
    }
    // done work
    if (injector_) {
      injector_.release();
    }
  });
}

void library::do_task(task tsk) { ch.push(tsk); }

int library::task_result() {
  int res = 0;
  ch_res.pop(res);
  return res;
}

library::~library() {
  ch.close();
  ch_res.close();
  worker.join();
  std::cout << "destructed" << std::endl;
}

fruit::Component<library_manager_base> get_injector() {
  return createComponent().install(get_caf_system).install(get_library_manager);
}
