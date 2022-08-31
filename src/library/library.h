#pragma once
#include "library_manager_base.h"
#include "singleton.h"
#include <caf/all.hpp>
#include <fruit/fruit.h>

#include <boost/fiber/all.hpp>

class library final : public Singleton<library> {
  using task = std::function<int(library_manager_base& lib)>;

public:
  library(token);
  ~library();

  void do_task(task tsk);
  int task_result();

private:
  boost::fibers::buffered_channel<task> ch{1024};
  boost::fibers::buffered_channel<int> ch_res{2};
  std::thread worker;
  std::unique_ptr<fruit::Injector<library_manager_base>> injector_;
};

fruit::Component<library_manager_base> get_injector();