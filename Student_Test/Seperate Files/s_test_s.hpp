#ifndef S_TEST_S_HPP
#define S_TEST_S_HPP

// Name stands for Student_test_static

#include "s_test_v.hpp"

// This File shouldn't be changed

//! Output-Handling

// Buffs the output of main_call inside namespace STUDENT to check if the output
// is correct
template <typename T>
bool check_output(T&& main_call, const std::string& expectedOutput) {
  std::stringstream output_stream;
  std::streambuf* old_buffer = std::cout.rdbuf(output_stream.rdbuf());

  std::forward<T>(main_call)();  // calls main() in namespace STUDENT

  std::cout.rdbuf(old_buffer);

  std::string STUDENTOutput = output_stream.str();

  if (STUDENTOutput == expectedOutput) {
    std::cout << "Student Output matches the expected output." << std::endl;
    std::cout << "Task completed.\n" << std::endl;
    return true;
  } else {
    std::cout << "Student Output does not match the expected output."
              << std::endl;
    std::cout << "- Expected Output: " << expectedOutput << std::endl;
    std::cout << "-  Student Output: " << STUDENTOutput << std::endl;
    return false;
  }
}

//! Check members output
// commented out the constexpr because I have SFINAE checking the members at
// compile time

// Checks for Memebers inside a class with has_member function (3 members)
template <typename T>
bool check_members3() {
  if /*constexpr*/ (has_members3<T>::value) {
    std::cout << "+ Found its 3 Members" << std::endl;
    return true;
  } else {
    std::cout << "+ Members not found" << std::endl;
    return false;
  }
}

// Checks for Memebers inside a class with has_member function (2 members)
template <typename T>
bool check_members2() {
  if /*constexpr*/ (has_members2<T>::value) {
    std::cout << "+ Found its 2 Members" << std::endl;
    return true;
  } else {
    std::cout << "+ Members not found" << std::endl;
    return false;
  }
}

// Checks for Memeber inside a class with has_member function (1 member)
template <typename T>
bool check_member() {
  if /*constexpr*/ (has_member<T>::value) {
    std::cout << "+ Found its Member" << std::endl;
    return true;
  } else {
    std::cout << "+ Member not found" << std::endl;
    return false;
  }
}

//! Class-Handling

// Only checks for class completeness because if class dont exsist in the first
// place to be called the compiler will complain naturally
template <typename T>
bool check_class() {
  if /*constexpr*/ (sizeof(T) > 0) {
    std::string str{typeid(T).name()};
    // Hardcode demangler for typeid - Doenst do it perfectly but I cant use
    // #include a demangler header file because my compiler cant find those
    str.erase(0, 10).pop_back();
    std::cout << "Found Class " << str << std::endl;
    return true;
  } else {
    // Should never output here! Reason above
    throw std::runtime_error("- - ERROR - -: Class not found.");
    return false;
  }
}

//! Univeral call for both class and its member/members and return bool

// Checks if the class/struct has valid members inside (3 members)
template <typename T>
bool checks3() {
  if (check_class<T>() && check_members3<T>()) {
    return true;
  } else {
    return false;
  }
}

// Checks if the class/struct has valid members inside (2 members)
template <typename T>
bool checks2() {
  if (check_class<T>() && check_members2<T>()) {
    return true;
  } else {
    return false;
  }
}

// Checks if the class/struct has valid member inside (1 member)
template <typename T>
bool check() {
  if (check_class<T>() && check_member<T>()) {
    return true;
  } else {
    return false;
  }
}

// The core of the program excecution
// * Has to be under namespace STUDENT because of the lambda expression
template <typename = void>
void testStudentCodeMAIN(const std::string& expectedOutput,
                         const bool& foundClass1, const bool& foundClass2,
                         const bool& foundClass3, const bool& foundClass4,
                         const bool& foundClass5) {
  if (foundClass1 && foundClass2 && foundClass3) {
    if (check_output([]() { STUDENT::main(); }, expectedOutput)) {
      std::cout << "- - Great Job! - -\n" << std::endl;
    } else {
      std::cout << "Try Again!\n" << std::endl;
    }
  } else {
    std::cout << "You forgot the member inside the class/struct!\n"
              << std::endl;
    std::cout << "Try Again!\n" << std::endl;
  }
}

#endif