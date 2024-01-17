#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include "car.hpp"
#include "cmd_functions.hpp"

int main() {
  cmdOnStart();

  Car myCar("Honda", "Civic");
  Car yourCar("Honda", "Ford");

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
    myCar.compareCars(yourCar);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what();
  } catch (...) {
    std::cerr << "An unexpected error occured in main function.\n";
  }

  Car testCar1;
  Car testCar2("Honda", "Civic", ON, -5.43);

  cmdOnEnd();

  return 0;
}
