// car.cpp
// This file contains the implementation of the Car class functions declared in car.hpp

#include "car.hpp"
#include "Config.hpp"

// Default constructor
Car::Car() : m_make("Ford"), m_model("Mustang"), m_engineState(OFF), m_totalDistance(0.0) {
  std::cout << "Default constructor running for " << m_make << " " << m_model << ".\n";
}

// Parameterized constructor (2/4 parameters)
Car::Car(str_t make, str_t model) : m_make(make), m_model(model), m_engineState(OFF), m_totalDistance(0.0) {
  std::cout << "Parameterized constructor (2/4) running for " << m_make << " " << m_model << ".\n";
}

// Parameterized constructor (4/4 parameters)
Car::Car(str_t make, str_t model, State engineState, double totalDistance)
    : m_make(make), m_model(model), m_engineState(engineState), m_totalDistance(totalDistance) {
      std::cout << "Parameterized constructor (4/4) running for " << m_make << " " << m_model << ".\n";
}

// Deconstructor
Car::~Car() noexcept {
  // Doesn't print the last 2 deconstructions (of the initial objects'myCar'
  // and 'yourCar' after the End Of the Program)
  if (!(EOPManager::getInstance().isEOP() && !Config::developerMode)) {
    std::cout << "Deconstructor running for " << m_make << " " << m_model << ".\n";
  }
}

// Public member functions

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
  }

  // Code to start the engine
  m_engineState = State::ON;
  std::cout << "Engine started.\n";
}

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
    std::cerr << e.what() << '\n';
  }
}

void Car::showTotalDistance() const {
  // Error check
  if (m_totalDistance == 0) {
    std::cout << "The car hasn't moved yet.\n";
  }

  std::cout << std::fixed << std::setprecision(CarConfig::kMaxKmDigits)
      << "Total distance travelled: " << m_totalDistance << "km\n";
}

void Car::compareCars(const Car& other) {
  std::cout << "[compareCars]: ";
  if (areCarsEqual(other)) {
    std::cout << "The cars are the same.\n";
  } else {
    std::cout << "The cars are not the same.\n";
  }
}
