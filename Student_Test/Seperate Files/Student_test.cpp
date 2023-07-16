// Student_test.cpp uses header files. Include "s_test_v.h" and "s_test_s.h"
// "s_test_s.h" shows undeclared identifier STUDENT but shouldnt be an issue if
// included at the right place

#include "s_test_v.hpp"
// #inlude "s_test_v.h" // File to change the searched members in a class

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

#include "s_test_s.hpp"
// #include "s_test_s.h" // Has to be under namepsace STUDENT for template
// testStudentCodeMAIN to work

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