// WStudent_test.cpp is the whole program in one file
// Works at least up to c++23

#include <iostream>
#include <sstream>
#include <string>

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

// Checks for printed()
template <typename T>
struct has_member<T, decltype(void(std::declval<T>().printed()))>
    : std::true_type {};

namespace STUDENT {

// * Student Code to test starts here / / / /

//? Possible task: Write a simple code. Create 3 classes/structs named ClassX,
//? ClassY and ClassY. ClassX should have a function called printed with an
//? output "Printed..." to std::cout. ClassY should have 2 variables named
//? printed and IDE. While ClassZ has 2 variables AMP and VOLT and a function
//? called OHM. Call function printed() in main.

#include <iostream>

using namespace std;

class ClassX {
 public:
  void printed() { cout << "Printed..." << endl; }
};

class ClassY {
 public:
  int printed;
  int IDE;
};

class ClassZ {
 public:
  void OHM(){};
  double AMP;
  float VOLT;
};

int main() {
  ClassX x;
  x.printed();
  return 0;
}

// * Student Code to test ends here / / / /

}  // namespace STUDENT

//! Output-Handling

// Buffs the output of main_call inside namespace STUDENT to check if the output
// is correct
template <typename T>
bool check_output(T&& main_call, const std::string& expectedOutput) {
  std::stringstream output_stream;
  std::streambuf* old_buffer = std::cout.rdbuf(output_stream.rdbuf());

  (main_call)();  // calls main() in namespace STUDENT

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
  auto placeholder = sizeof(T);
  if /*constexpr*/ (placeholder > 0) {
    std::string strClass = typeid(T).name();

    //  Hardcode demangler for typeid

    // The mangled code is N7STUDENT6ClassXE. N = namespace, 7 = number of
    // character of namespace, 6 = number of character of class and E at the end
    // as end of character stop. I now search for the last number and delete
    // everything in front including the number and delete the E at the end.
    // This should be a very reliable way to demangle the class for this
    // program.
    size_t lastIntegerPos = strClass.size();
    while (lastIntegerPos > 0 && !std::isdigit(strClass[lastIntegerPos - 1])) {
      lastIntegerPos--;
    }

    std::string strClassReadable{strClass.substr(lastIntegerPos)};
    strClassReadable.pop_back();

    std::cout << "Found Class " << strClassReadable << std::endl;
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
    if (check_output(*(STUDENT::main), expectedOutput)) {
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

// Here call "check<STUDENT::(the class and member to check)>()"
// Replace with "true" if less classes are being checked
// Used static_assert here to maybe find the issue faster though my compiler
// doesnt output those messages when calling a non-existent class
void testStudentCode() {
  static_assert(std::is_class_v<STUDENT::ClassX>,
                "- - ERROR - -: ClassX not found.");
  bool foundClass1 = check<STUDENT::ClassX>();

  static_assert(std::is_class_v<STUDENT::ClassY>,
                "- - ERROR - -: ClassY not found.");
  bool foundClass2 = checks2<STUDENT::ClassY>();

  static_assert(std::is_class_v<STUDENT::ClassZ>,
                "- - ERROR - -: ClassZ not found.");
  bool foundClass3 = checks3<STUDENT::ClassZ>();

  bool foundClass4 = true;
  bool foundClass5 = true;

  // Here insert the expexted Output with \n
  std::string expectedOutput = "Printed...\n";

  ::testStudentCodeMAIN<>(expectedOutput, foundClass1, foundClass2, foundClass3,
                          foundClass4, foundClass5);
}

int main() {
  testStudentCode();
  return 0;
}

/* At least the class must exist to be called and the program to run. */