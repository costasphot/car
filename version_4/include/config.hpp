// config.hpp
// Configuration settings for the Car System

#pragma once

#include <iostream>

namespace Config {
  constexpr bool developerMode = false; // Set it to true for development, false for production
  constexpr bool confidentialOverride = false; // Might contain sensitive information
}
