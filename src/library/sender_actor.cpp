#include "sender_actor.h"
#include "atoms.h"
#include "duration.h"

using namespace caf;
using namespace std;

sender_actor::sender_actor(caf::actor_config &cfg) : event_based_actor(cfg) {}

caf::behavior sender_actor::make_behavior() {

  auto await_cmd = message_handler{
      [=](cmd_atom, const std::string &cmd) -> result<std::string> {
        duration::instance().end();
        cout << "cmd sender: " << cmd << endl;
        return {"test resp"};
      }};

  auto await_init = message_handler{[=](init_atom, const actor &next) {
    next_ = next;
    become(await_cmd);
  }};

  return await_init;
}
void sender_actor::on_exit() { destroy(next_); }