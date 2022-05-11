#include "caf_system_config.h"
#include "caf/timespan.hpp"
#include <iostream>
caf_system_config::caf_system_config() {
  auto &caf_group = content["caf"].as_dictionary();
  auto &scheduler_group = caf_group["scheduler"].as_dictionary();
  put(scheduler_group, "policy", "sharing");
  // load<caf::io::middleman>();
}
