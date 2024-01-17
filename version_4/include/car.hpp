// car.hpp
// This file contains the declaration of the Car class
// It provides functionality for controlling a simple car with engine and distance tracking

#pragma once

#include <iostream>
#include <string>
#include <stdexcept> // Include the header for standard exceptions
#include <iomanip> // Include the header for manipulators
#include <cmath>

// Contains configuration constants for the Car class
namespace CarConfig {
  // Sets the max decimal digits for kilometers to 2
  constexpr std::uint8_t kMaxKmDigits = 2;
}

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
    Car(std::string make, std::string model);
    Car(std::string make, std::string model, State engineState, double totalDistance);
    Car(const Car&);
    ~Car() noexcept;

    // Overloaded operator function
    friend std::ostream& operator<<(std::ostream&, const Car&);

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
    std::string getMake() const;
    std::string getModel() const; 
    std::string getEngineState() const;
    double getTotalDistance() const;

  private:
    // Private member variables
    std::string m_make;
    std::string m_model;
    State m_engineState;
    double m_totalDistance;

    // Helper function for parameter validation
    static void validateParameters(const std::string&, const std::string&, State, double);
    void handleValidationFailure(const std::invalid_argument& e);
};

// Inline getters
inline std::string Car::getMake() const { return m_make; }
inline std::string Car::getModel() const { return m_model; }
inline std::string Car::getEngineState() const { return (m_engineState == State::ON ? "ON" : "OFF"); }
inline double Car::getTotalDistance() const { return m_totalDistance; }

// Inline public member functions
inline void Car::showEngineState() const {
  std::cout << "The engine is " << getEngineState() << ".\n";
}

inline void Car::showCarDetails() const {
  std::cout << "The car is a " << m_make << " " << m_model << ".\n";
}

inline bool Car::areCarsEqual(const Car& other) const {
  return (m_make == other.m_make) && (m_model == other.m_model);
}
