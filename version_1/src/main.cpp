#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "car.hpp"

void cmdOnStart() {
  #ifdef _WIN32
    system("cls");
    #ifdef _WIN64 
      system("title Car Class (x64)");
    #else
      system("title Car Class (x32)");
    #endif
    system("color 3");
  #else
    std::runtime_error("Incompatible operating system!\n");
    exit(EXIT_FAILURE); // Handle non-Windows systems differently, or provide an alternate solution
  #endif

  std::cout << "This program implements a class for cars.\n\n";
}

void cmdOnEnd() {
  // Pause the program before returning 0
  std::cout << "\nPress Enter to exit...";
  std::cin.get();
}

int main() {
  cmdOnStart();

  Car myCar("Honda", "Civic");

  try {
    myCar.showCarDetails();
    myCar.showEngineState();
    myCar.startEngine();
    myCar.showEngineState();
    myCar.drive(5.2);
    myCar.drive(3.2);
    myCar.startEngine();
    myCar.stopEngine();
    myCar.showTotalDistance();
    myCar.drive(7.1);
    myCar.stopEngine();
    myCar.showTotalDistance();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  cmdOnEnd();

  return 0;
}
