#pragma once
#include "singleton.h"
#include <chrono>
#include <iostream>

class duration final : public Singleton<duration> {
public:
  duration(token) {}
  ~duration() {}
  void begin() { t_ = std::chrono::system_clock::now(); };
  void end() {
    std::cout << "time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now() - t_)
                     .count()
              << std::endl;
  }

private:
  std::chrono::system_clock::time_point t_;
};