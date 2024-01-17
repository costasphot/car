// car.cpp
// This file contains the implementation of the Car class functions declared in car.hpp

#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
#include "car.hpp"
#include "config.hpp"

/**
 * @brief Validates the parameters for car initialization.
 *
 * Checks if the make and model strings are non-empty and if the total distance is non-negative.
 * Throws an std::invalid_argument exception with an appropriate error message if validation fails.
 *
 * @param make The make of the car.
 * @param model The model of the car.
 * @param engineState The initial state of the car engine.
 * @param totalDistance The initial total distance traveled by the car.
 */
void Car::validateParameters(const std::string& make, const std::string& model, State engineState, double totalDistance) {
  if (make.empty() || model.empty()) {
    throw std::invalid_argument("Error: Make and model cannot be empty.\n");
  }

  if (totalDistance < 0.0) {
    throw std::invalid_argument("Error: Total distance cannot be negative.\n");
  }
}

/**
 * @brief Handles the failure of parameter validation.
 *
 * If in developer mode, logs the validation failure details, takes corrective action by setting default values,
 * and does not rethrow the exception to propagate it up the call stack.
 *
 * @param e The std::invalid_argument exception representing the validation failure.
 */
void Car::handleValidationFailure(const std::invalid_argument& e) {
  if (Config::developerMode) {
    std::cerr << "Validation failure: " << e.what();

    // Log additional information
    std::cerr << "Make: " << m_make << ", Model: " << m_model << ", Engine State: "
        << getEngineState() << ", Total Distance: " << m_totalDistance << '\n';

    // Take corrective action
    // Set default values or perform other recovery actions
    m_make = "Ford";
    m_model = "Mustang";
    m_engineState = OFF;
    m_totalDistance = 0.0;

    // Shouldn't rethrow the exception to propagate it up the call stack
  }
}

/**
 * @brief Default constructor for the Car class.
 *
 * Initializes a car with default values and validates the parameters.
 * Logs construction details if in developer mode and handles validation failure.
 */
Car::Car() : m_make("Ford"), m_model("Mustang"), m_engineState(OFF), m_totalDistance(0.0) {
  try {
    validateParameters(m_make, m_model, m_engineState, m_totalDistance);
    if (Config::developerMode) {
      std::cout << "Default constructor running for " << *this << ".\n";
    }
  } catch (const std::invalid_argument& e) {
    handleValidationFailure(e);
  }
}

/**
 * @brief Parameterized constructor for the Car class with 2 out of 4 parameters.
 *
 * Initializes a car with make and model, sets default values for other parameters,
 * and validates the parameters. Logs construction details if in developer mode and handles validation failure.
 *
 * @param make The make of the car.
 * @param model The model of the car.
 */
Car::Car(std::string make, std::string model)
    : m_make(make), m_model(model), m_engineState(OFF), m_totalDistance(0.0) {
      try {
        validateParameters(make, model, m_engineState, m_totalDistance);
        if (Config::developerMode) {
          std::cout << "Parameterized constructor (2/4) running for " << *this << ".\n";
        }
      } catch (const std::invalid_argument& e) {
        handleValidationFailure(e);
      }
}

/**
 * @brief Parameterized constructor for the Car class with all 4 parameters.
 *
 * Initializes a car with make, model, engine state, and total distance,
 * and validates the parameters. Logs construction details if in developer mode and handles validation failure.
 *
 * @param make The make of the car.
 * @param model The model of the car.
 * @param engineState The initial state of the car engine.
 * @param totalDistance The initial total distance traveled by the car.
 */
Car::Car(std::string make, std::string model, State engineState, double totalDistance)
    : m_make(std::move(make)), m_model(std::move(model)), m_engineState(engineState), m_totalDistance(totalDistance) {
      try {
        validateParameters(make, model, engineState, totalDistance);
        if (Config::developerMode) {
          std::cout << "Parameterized constructor (4/4) running for " << *this << ".\n";
        }
      } catch (const std::invalid_argument& e) {
        handleValidationFailure(e);
      }
}

/**
 * @brief Copy constructor for the Car class.
 *
 * Initializes a car with the same values as another car, validates the parameters,
 * and logs construction details if in developer mode. Handles validation failure.
 *
 * @param other The Car object to copy.
 */
Car::Car(const Car& other) : m_make(other.m_make), m_model(other.m_model),
    m_engineState(other.m_engineState), m_totalDistance(other.m_totalDistance) {
      try {
        validateParameters(m_make, m_model, m_engineState, m_totalDistance);
        if (Config::developerMode) {
          std::cout << "Copy constructor running for " << *this << ".\n";
        }
      } catch (const std::invalid_argument& e) {
        handleValidationFailure(e);
      }
}

/**
 * @brief Destructor for the Car class.
 *
 * Logs destruction details if in developer mode and confidential override is enabled.
 * Called automatically when a Car object goes out of scope.
 */
Car::~Car() noexcept {
  if (Config::developerMode && Config::confidentialOverride) {
    std::cout << "Destructor running for " << *this << ".\n";
  }
}

/**
 * @brief Overloaded stream insertion operator for the Car class.
 *
 * @param os The output stream.
 * @param c The Car object to output.
 * @return The modified output stream.
 */
std::ostream& operator<<(std::ostream& os, const Car& c) {
  os << c.m_make << " " << c.m_model;
  return os;
}

/**
 * @brief Starts the car engine.
 *
 * If the engine is already ON, it prints a message and does nothing.
 * Otherwise, it starts the engine and prints a confirmation message.
 */
void Car::startEngine() noexcept {
  // Error check
  if (m_engineState == State::ON) {
    std::cout << "The engine is already ON.\n";
    return;
  }

  // Code to start the engine
  m_engineState = State::ON;
  std::cout << "Engine started.\n";
}

/**
 * @brief Stops the car engine.
 *
 * If the engine is already OFF, it prints a message and does nothing.
 * Otherwise, it stops the engine and prints a confirmation message.
 */
void Car::stopEngine() noexcept{
  // Error check
  if (m_engineState == State::OFF) {
    std::cout << "The engine is already OFF.\n";
    return;
  }

  // Code to stop the engine
  m_engineState = State::OFF;
  std::cout << "Engine stopped.\n";
}

/**
 * @brief Drives the car for a specified distance.
 *
 * Validates the distance and engine state, and increments the total distance traveled.
 * Prints a message indicating the distance driven.
 *
 * @param distance The distance to drive in kilometers.
 */
void Car::drive(double distance) {
  try {
    // Error checks
    if (std::isnan(distance)) {
      throw std::invalid_argument("Error: Invalid distance (NaN) entered in drive function!");
    }

    if (!std::isfinite(distance)) {
      throw std::invalid_argument("Error: Invalid distance (infinite) entered in drive function!");
    }

    if (m_engineState == State::OFF || distance < 0 || distance == 0) {
      throw std::invalid_argument("Error: Cannot drive. Ensure the engine is on and provide a positive distance.");
    }

    // Code to drive the car
    m_totalDistance += distance;
    std::cout << std::fixed << std::setprecision(CarConfig::kMaxKmDigits)
    << "Driving " << distance << "km\n";
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what();
  } catch (const std::exception& e) {
    std::cerr << "An unexpected error occured in drive function: " << e.what();
  } catch (...) {
    std::cerr << "An unexpected error occured in drive function.\n";
  }
}

/**
 * @brief Displays the total distance traveled by the car.
 *
 * If the total distance is zero, it prints a message indicating that the car hasn't moved yet.
 * Otherwise, it prints the total distance with fixed precision.
 */
void Car::showTotalDistance() const {
  // Error check
  if (m_totalDistance == 0) {
    std::cout << "The car hasn't moved yet.\n";
  }

  std::cout << std::fixed << std::setprecision(CarConfig::kMaxKmDigits)
      << "Total distance travelled: " << m_totalDistance << "km\n";
}

/**
 * @brief Compares two cars for equality.
 *
 * Prints a message indicating whether the cars are the same or not based on their make and model.
 *
 * @param other The Car object to compare with.
 */
void Car::compareCars(const Car& other) {
  std::cout << "[compareCars]: ";
  if (areCarsEqual(other)) {
    std::cout << "The cars are the same.\n";
  } else {
    std::cout << "The cars are not the same.\n";
  }
}
