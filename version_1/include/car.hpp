#pragma once

#include <iostream>
#include <string>
#include <stdexcept> // Include the header for standard exceptions
#include <iomanip> // Include the header for manipulators
// Sets the max decimal digits for kilometers to 2

using str_t = std::string;

constexpr std::uint8_t MAX_DIGITS = 2;

// Later defines the engine's state
enum State { ON = 1, OFF = 0 };

class Car {
  public:
    // Constructor
    Car(str_t make, str_t model) : make_(make), model_(model) {}

    // Declaration of public member functions
    void startEngine();
    void stopEngine();
    void drive(double /* in kilometers */);
    void showTotalDistance() const;
    void showEngineState() const;
    void showCarDetails() const;
    
    // Declaration of getters
    str_t getMake() const;
    str_t getModel() const; 
    str_t getEngineState() const;
    double getTotalDistance() const;

  private:
    // Private member variables
    str_t make_;
    str_t model_;
    State engineState = OFF;
    double totalDistance = 0.0;
};

// Definition of public member functions
void Car::startEngine() {
  // Error check
  if (engineState == ON) {
    std::cout << "The engine is already ON.\n";
  }

  // Code to start the engine
  engineState = ON;
  std::cout << "Engine started.\n";
}

void Car::stopEngine() {
  // Error check
  if (engineState == OFF) {
    std::cout << "The engine is already OFF.\n";
    return;
  }

  // Code to stop the engine
  engineState = OFF;
  std::cout << "Engine stopped.\n";
}

void Car::drive(double distance) {
  // Error checks
  if (engineState == OFF) {
    std::cout << "The engine is off. Automatically starting the engine...\n";
    startEngine();
  }

  if (distance < 0 ) {
    std::cout << "Error: Negative distance entered!\n";
    return;
  }

  if (distance == 0) {
    std::cout << "The car remains stationary.\n";
    return;
  }

  // Code to drive the car
  totalDistance += distance;
  std::cout << std::fixed << std::setprecision(MAX_DIGITS)
      << "Driving " << distance << "km\n";
}

void Car::showTotalDistance() const {
  // Error check
  if (totalDistance == 0) {
    std::cout << "The car hasn't moved yet.\n";
  }

  std::cout << std::fixed << std::setprecision(MAX_DIGITS)
      << "Total distance travelled: " << totalDistance << "km\n";
}

void Car::showEngineState() const {
  std::cout << "The engine is " << getEngineState() << ".\n";
}

void Car::showCarDetails() const {
  std::cout << "The car is a " << make_ << " " << model_ << ".\n";
}

// Definition of getters
str_t Car::getMake() const {
  return make_;
}

str_t Car::getModel() const {
  return model_;
}

str_t Car::getEngineState() const {
  switch(engineState) {
    case ON:
      return "ON";
    case OFF:
      return "OFF";
    default:
      throw std::logic_error("Unexpected engine state encountered!\n");
  }
}

double Car::getTotalDistance() const {
  return totalDistance;
}