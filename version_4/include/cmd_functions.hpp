// cmd_functions.hpp
// Header file for command-related functions

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <limits>

// Function declarations for command-related operations
void cmdOnStart();
void cmdOnEnd();
#ifdef _WIN32
  void configureWindowsConsole();
#elif __linux__
  void configureLinuxConsole();
#elif defined(__unix__)
  void configureUnixConsole();
#else
  void handleNonWindowsSystem();
#endif
