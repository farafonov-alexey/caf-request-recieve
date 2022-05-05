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
  init_global_meta_objects<caf::id_block::library>();
  core::init_global_meta_objects();
  injector_ = make_unique<fruit::Injector<library_manager_base>>(get_injector);
}
library::~library() {
  std::cout << "destructed" << std::endl;
  if (injector_) {
    injector_.release();
  }
}
library_manager_base &library::library_manager() {
  return injector_->get<library_manager_base &>();
}

fruit::Component<library_manager_base> get_injector() {
  return createComponent().install(get_caf_system).install(get_library_manager);
}
