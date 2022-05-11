#include "library_manager.h"

#include "atoms.h"
#include "caf/all.hpp"
#include "caf/defaults.hpp"
#include "caf_system_base.h"
#include "duration.h"
#include "reciever_actor.h"
#include "sender_actor.h"

using namespace std;
class library_manager : public library_manager_base {
public:
  INJECT(library_manager(caf_system_base *system)) : system_(system){};
  int library_manager::create() override {
    sender_ = system_->system().spawn<sender_actor>();
    reciever_ = system_->system().spawn<reciever_actor>();
    caf::scoped_actor self{system_->system()};
    self->send(sender_, init_atom_v, reciever_);
    return 0;
  }
  void library_manager::destroy() override {
    caf::actor empty;
    sender_ = empty;
    reciever_ = empty;
  }
  int library_manager::do_stuff() override {
    caf::scoped_actor self{system_->system()};
    duration::instance().begin();
    self->request(sender_, chrono::seconds(10), cmd_atom_v, "command_1")
        .receive(
            [&](const std::string &data) {
              // aout(self) << "data: " << data << endl;
            },
            [&](caf::error &err) {
              aout(self) << "err: " << to_string(err) << endl;
            });
    return 0;
  }

private:
  caf_system_base *system_;

  caf::actor sender_;
  caf::actor reciever_;
};

fruit::Component<fruit::Required<caf_system_base>, library_manager_base>
get_library_manager() {
  return fruit::createComponent().bind<library_manager_base, library_manager>();
}