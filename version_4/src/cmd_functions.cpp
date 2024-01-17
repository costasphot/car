// cmd_functions.cpp
// Implementation file for command-related functions

#include "cmd_functions.hpp"

// Function definition for command-related operations at program start
void cmdOnStart() {
  #ifdef _WIN32
    configureWindowsConsole();
  #elif __linux__
    configureLinuxConsole();
  #elif defined(__unix__)
    configureUnixConsole();
  #else
    handleNonWindowsSystem();
  #endif

  std::cout << "This program implements a class for cars.\n\n";
}

void cmdOnEnd() {
  // Pause the program before returning 0
  std::cout << "\nPress Enter to exit...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#ifdef _WIN32
// Function definition to configure the Windows console
void configureWindowsConsole() {
  system("cls");
  #if _WIN64
    // Visual Studio 2019 or later
    system("title Car Class (x64)");
  #else
    // Handle older versions if needed
    system("title Car Class (x32)");
  #endif
  system("color 3");
}
#elif __linux__
void configureLinuxConsole() {
  system("clear");
  system("echo -e '\033]0;Car Class (Linux)\007'");
}
#elif defined(__unix__)
void configureUnixConsole() {
  system("clear");
  system("echo -e '\033]0;Car Class (UNIX)\007'");
}
#else
// Function definition for handling non-Windows systems
void handleNonWindowsSystem() {
  std::cerr << "Warning: Incompatible operating system!\n";
  // Add any necessary handling for non-Windows systems here
}
#endif
