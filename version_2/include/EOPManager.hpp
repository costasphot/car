// EOPManager.hpp
#pragma once

// Be extra cautious
#ifndef EOP_MANAGER_HPP
#define EOP_MANAGER_HPP

#include <iostream>

class EOPManager {
public:
  // Global access method
  static EOPManager& getInstance();
  bool isEOP() const;
  void setEOP(bool);

private:
  EOPManager(); // Private constructor to enforce singleton pattern
  bool EOP = false; // End Of Program flag
};

// Declare the EOP variable
extern bool EOP;

inline EOPManager& EOPManager::getInstance() {
  static EOPManager instance; // Guaranteed to be destroyed, instantiated on first use
  return instance;
}

// Function to check End Of Program flag
inline bool EOPManager::isEOP() const {
  return EOP;
}

// Function to set End Of Program flag
inline void EOPManager::setEOP(bool value) {
  EOP = value;
}

#endif // EOP_MANAGER_HPP
