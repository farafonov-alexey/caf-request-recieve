#include <iostream>
#include <string>

#include "caf/actor_ostream.hpp"
#include "caf/actor_system.hpp"
#include "caf/caf_main.hpp"
#include "caf/event_based_actor.hpp"
#include "caf/scoped_actor.hpp"
#include "caf/timestamp.hpp"

using namespace caf;

using namespace std::literals;

behavior clock_actor() {
  return {[](get_atom) { return make_timestamp(); }};
}

void request(actor_system &sys, caf::actor &clk) {
  scoped_actor self{sys};
  auto t0 = make_timestamp();
  self->request(clk, 5s, get_atom_v)
      .receive(
          [&](timestamp t1) {
            auto t2 = make_timestamp();
            std::cout << "request-response:\n"
                      << "t0: " << caf::deep_to_string(t0) << '\n'
                      << "t1: " << caf::deep_to_string(t1) << '\n'
                      << "t2: " << caf::deep_to_string(t2) << '\n'
                      << "delta (full): " << caf::deep_to_string(t2 - t0)
                      << '\n'
                      << "delta (self -> clock): "
                      << caf::deep_to_string(t1 - t0) << '\n'
                      << "delta (clock -> self): "
                      << caf::deep_to_string(t2 - t1) << '\n';
          },
          [](const error &) {});
}
void caf_main(actor_system &sys) {
  // request-response
  auto clk = sys.spawn(clock_actor);
  request(sys, clk);
  request(sys, clk);
}

CAF_MAIN()