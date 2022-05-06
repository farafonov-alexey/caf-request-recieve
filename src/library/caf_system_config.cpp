#include "caf_system_config.h"
#include "caf/timespan.hpp"
#include <iostream>
caf_system_config::caf_system_config() {
  auto &caf_group = content["caf"].as_dictionary();
  // -- work-stealing parameters
  auto &work_stealing_group = caf_group["work-stealing"].as_dictionary();
  put(work_stealing_group, "relaxed-sleep-duration", caf::timespan{1'000'000});
  std::cout << "config" << to_string(dump_content()) << std::endl;
  // load<caf::io::middleman>();
}
