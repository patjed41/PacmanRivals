#pragma once

#include <iostream>

namespace err {

  inline void check(bool condition) {
    if (!condition) {
      std::cout << "FAIL";
      exit(0);
    }
  }

  inline void check(bool condition, int label) {
    if (!condition) {
      std::cout << "FAIL - " << label;
      exit(0);
    }
  }

  inline void check(bool condition, std::string message) {
    if (!condition) {
      std::cout << "FAIL: " << message;
      exit(0);
    }
  }

  template<typename T>
  inline void checkEqual(T a, T b) {
    if (a != b) {
      std::cout << "FAIL: expected " << a << ", actual " << b;
      exit(0);
    }
  }

  template<typename T>
  inline void checkEqual(T a, T b, int label) {
    if (a != b) {
      std::cout << "FAIL - " << label << ": expected " << a << ", actual " << b;
      exit(0);
    }
  }

  template<typename T>
  inline void checkEqual(T a, T b, std::string message) {
    if (a != b) {
      std::cout << "FAIL: " << message << ", expected " << a << ", actual " << b;
      exit(0);
    }
  }

  inline void error() {
    std::cout << "FAIL";
    exit(0);
  }

  inline void error(int label) {
    std::cout << "FAIL - " << label;
    exit(0);
  }

  inline void error(std::string message) {
    std::cout << "FAIL: " << message;
    exit(0);
  }

}
