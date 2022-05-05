#pragma once

#include "caf/all.hpp"

class reciever_actor : public caf::event_based_actor {

public:
  reciever_actor(caf::actor_config &cfg);
  caf::behavior make_behavior() override;

private:
};
