// car.hpp
#pragma once

// Be extra cautious
#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>
#include <stdexcept> // Include the header for standard exceptions
#include <iomanip> // Include the header for manipulators

#include "EOPManager.hpp"

// Sets the max decimal digits for kilometers to 2
constexpr std::uint8_t MAX_DIGITS = 2;

// Just abbreviate this whole thing into a new and nicer type
using str_t = std::string;

// Later defines the engine's state
enum State { ON = 1, OFF = 0 };

// Car class represents a simple car with engine control and distance tracking.
class Car {
  public:
    // Default constructor
    Car();

    // Parameterized constructor (2/4)
    Car(str_t make, str_t model);

    // Parameterized constructor (4/4)
    Car(str_t make, str_t model, State engineState, double totalDistance);

    // Deconstructor
    ~Car();

    // Public member functions
    void startEngine();
    void stopEngine();
    void drive(double /* in kilometers */);
    void showTotalDistance() const;
    void showEngineState() const;
    void showCarDetails() const;
    bool areCarsEqual(const Car& /* other */) const;

    // Getters
    str_t getMake() const;
    str_t getModel() const; 
    str_t getEngineState() const;
    double getTotalDistance() const;

  private:
    // Private member variables
    str_t make_;
    str_t model_;
    State engineState;
    double totalDistance;

    // Friendly functions
    friend void compareCars(const Car&, const Car&);
};

#endif // CAR_HPP
