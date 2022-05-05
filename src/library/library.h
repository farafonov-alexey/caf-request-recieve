#pragma once
#include "library_manager_base.h"
#include "singleton.h"
#include <caf/all.hpp>
#include <fruit/fruit.h>

class library final : public Singleton<library> {
public:
  library(token);
  ~library();
  library_manager_base& library_manager();

private:
  std::unique_ptr<fruit::Injector<library_manager_base>> injector_;
};

fruit::Component<library_manager_base> get_injector();