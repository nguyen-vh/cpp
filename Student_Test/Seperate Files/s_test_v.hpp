#ifndef S_TEST_V_HPP
#define S_TEST_V_HPP

// Name stands for Student_test_Variable

#include <iostream>
#include <sstream>
#include <string>

// This File needs to be changed to adapt to the task

//! Check SFINAE fallbacks from an answer on stackoverflow

// Universal Template for has_mambers to fallblack (3 members check)
template <typename T, typename = void>
struct has_members3 : std::false_type {};

// Universal Template for has_mambers to fallblack (2 members check)
template <typename T, typename = void>
struct has_members2 : std::false_type {};

// Universal Template for has_mamber to fallblack (1 member)
template <typename T, typename = void>
struct has_member : std::false_type {};

//! Check members searches from an answer on stackoverflow

// Checks for printed()
template <typename T>
struct has_member<T, decltype(void(std::declval<T>().printed()))>
    : std::true_type {};

// Checks for printed() and ID in one class/struct (3 members)
template <typename T>
struct has_members3<T, std::void_t<decltype(std::declval<T>().OHM()),
                                   decltype(std::declval<T>().AMP),
                                   decltype(std::declval<T>().VOLT)>>
    : std::true_type {};

// Checks for printed() and ID in one class/struct (2 members)
template <typename T>
struct has_members2<T, std::void_t<decltype(std::declval<T>().printed),
                                   decltype(std::declval<T>().IDE)>>
    : std::true_type {};

// Checks for ID (1 member=)
template <typename T>
struct has_member<T, decltype(void(std::declval<T>().ID))> : std::true_type {};

#endif