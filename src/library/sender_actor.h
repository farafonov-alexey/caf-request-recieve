#pragma once

#include "caf/all.hpp"

class sender_actor : public caf::event_based_actor {
public:
  sender_actor(caf::actor_config &cfg);
  caf::behavior make_behavior() override;
  void on_exit();

private:
  caf::actor next_;
};