#pragma once

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>
#include <iostream>

#define START auto start_time = std::chrono::high_resolution_clock::now();

#define STOP                                                             \
  auto end_time = std::chrono::high_resolution_clock::now();             \
  std::chrono::microseconds duration_micro =                             \
      std::chrono::duration_cast<std::chrono::microseconds>(end_time -   \
                                                            start_time); \
  long long microseconds = duration_micro.count();                       \
  long long milliseconds = microseconds / 1000;                          \
  microseconds %= 1000;                                                  \
  long long seconds = milliseconds / 1000;                               \
  milliseconds %= 1000;                                                  \
  long long minutes = seconds / 60;                                      \
  seconds %= 60;                                                         \
  std::cout << "\033[32m"                                                \
            << "Measured time: "                                         \
            << "\033[1m";                                                \
  if (minutes > 0) {                                                     \
    std::cout << minutes << "\033[0m\033[32m minutes";                   \
  } else if (seconds >= 10) {                                            \
    std::cout << seconds << "\033[0m\033[32m seconds";                   \
  } else if (milliseconds >= 10) {                                       \
    std::cout << milliseconds << "\033[0m\033[32m milliseconds";         \
  } else {                                                               \
    std::cout << microseconds << "\033[0m\033[32m microseconds";         \
  }                                                                      \
  std::cout << "\033[0m" << std::endl;

#endif

// START;
/*
code to measure
*/
//  STOP;
