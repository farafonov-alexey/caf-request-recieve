#include "caf_system.h"
class caf_system : public caf_system_base {
public:
  INJECT(caf_system()){};
  caf_system_config& config() override {
    return cfg_;
  }
  caf::actor_system& system() override {
    return system_;
  }

private:
  caf_system_config cfg_;
  caf::actor_system system_{cfg_};
};

fruit::Component<caf_system_base> get_caf_system() {
  return fruit::createComponent().bind<caf_system_base, caf_system>();
}
