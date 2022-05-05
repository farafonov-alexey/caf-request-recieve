#pragma once
#include "caf/all.hpp"
#include "caf_system_config.h"

class caf_system_base {
public:
  virtual caf_system_config& config() = 0;
  virtual caf::actor_system& system() = 0;
};
