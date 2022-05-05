#include "reciever_actor.h"
#include "atoms.h"
#include <iostream>

using namespace caf;
using namespace std;
reciever_actor::reciever_actor(caf::actor_config &cfg)
    : event_based_actor(cfg) {}

caf::behavior reciever_actor::make_behavior() {
  return message_handler{[=](cmd_atom, const std::string &cmd) {
    cout << "cmd reciever: " << cmd << endl;
  }};
}