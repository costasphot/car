// car.hpp
// This file contains the declaration of the Car class
// It provides functionality for controlling a simple car with engine and distance tracking

#pragma once

#include <iostream>
#include <string>
#include <stdexcept> // Include the header for standard exceptions
#include <iomanip> // Include the header for manipulators
#include <cmath>

#include "EOPManager.hpp"

// Contains configuration constants for the Car class
namespace CarConfig {
  // Sets the max decimal digits for kilometers to 2
  constexpr std::uint8_t kMaxKmDigits = 2;
}

// Just abbreviate this whole thing into a new and nicer type
using str_t = std::string;

// Later defines the engine's state
enum State { ON = true, OFF = false };

/**
 * @brief Represents a simple car with engine control and distance tracking.
 *
 * The Car class provides basic functionality to start/stop the engine, drive,
 * and display information about the car.
 */
class Car {
  public:
    // Constructors and Destructor
    Car();
    Car(str_t make, str_t model);
    Car(str_t make, str_t model, State engineState, double totalDistance);
    ~Car() noexcept;

    // Engine Control
    void startEngine() noexcept;
    void stopEngine() noexcept;

    // Driving Operations
    void drive(double /* in kilometers */);
    void showTotalDistance() const;

    // Information Display
    void showEngineState() const;
    void showCarDetails() const;
    void compareCars(const Car& /* other */);
    bool areCarsEqual(const Car& /* other */) const;

    // Inline getters
    str_t getMake() const;
    str_t getModel() const; 
    str_t getEngineState() const;
    double getTotalDistance() const;

  private:
    // Private member variables
    str_t m_make;
    str_t m_model;
    State m_engineState;
    double m_totalDistance;
};

// Inline getters
inline str_t Car::getMake() const { return m_make; }
inline str_t Car::getModel() const { return m_model; }
inline str_t Car::getEngineState() const { return (m_engineState == State::ON ? "ON" : "OFF"); }
inline double Car::getTotalDistance() const { return m_totalDistance; }

// Inline public member functions
inline void Car::showEngineState() const {
  std::cout << "The engine is " << (m_engineState == State::ON ? "ON" : "OFF") << ".\n";
}

inline void Car::showCarDetails() const {
  std::cout << "The car is a " << m_make << " " << m_model << ".\n";
}

inline bool Car::areCarsEqual(const Car& other) const {
  return (m_make == other.m_make) && (m_model == other.m_model);
}
