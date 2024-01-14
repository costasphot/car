#include "car.hpp"

// Default constructor
Car::Car() : make_("Ford"), model_("Mustang"), engineState(OFF), totalDistance(0.0) {
  std::cout << "Default constructor running for " << make_ << " " << model_ << ".\n";
}

// Parameterized constructor (2/4 parameters)
Car::Car(str_t make, str_t model) : make_(make), model_(model), engineState(OFF), totalDistance(0.0) {
  std::cout << "Parameterized constructor (2/4) running for " << make_ << " " << model_ << ".\n";
}

// Parameterized constructor (4/4 parameters)
Car::Car(str_t make, str_t model, State engineState, double totalDistance)
    : make_(make), model_(model), engineState(engineState), totalDistance(totalDistance) {
      std::cout << "Parameterized constructor (4/4) running for " << make_ << " " << model_ << ".\n";
}

// Deconstructor
Car::~Car() {
  // Doesn't print the last 2 deconstructions (of the initial objects'myCar'
  // and 'yourCar' after the End Of the Program)
  if (!EOPManager::getInstance().isEOP()) {
    std::cout << "Deconstructor running for " << make_ << " " << model_ << ".\n";
  }
}

// Public member functions
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
    throw std::invalid_argument("Error: Negative distance entered in drive function!\n");
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

bool Car::areCarsEqual(const Car& other) const {
  return (make_ == other.make_) && (model_ == other.model_);
}

// Getters
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

// Friendly functions
void compareCars(const Car& c1, const Car& c2) {
  std::cout << "[compareCars]: ";
  if (c1.areCarsEqual(c2)) {
    std::cout << "The cars are the same.\n";
  } else {
    std::cout << "The cars are not the same.\n";
  }
}
