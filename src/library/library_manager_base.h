#pragma once
#include <string>
class library_manager_base {
public:
  virtual int create() = 0;
  virtual int do_stuff() = 0;
  virtual void destroy() = 0;
};
