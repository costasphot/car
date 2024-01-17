# Car System Architecture

## Table of Contents

1. [Overview](#overview)
2. [Components](#components)
	- [Car Class](#1-car-class)
	  - [Functions](#functions)
	  - [Constructors](#constructors)
	  - [Destructor](#destructor)
	  - [Inline Getters](#inline-getters)
	- [Config Class](#2-config-class)
	  - [Settings](#settings)
	- [Other Files](#3-other-files)
3. [Usage](#usage)
4. [Error Handling](#error-handling)
5. [Developer Mode](#developer-mode)
6. [Confidential Override](#confidential-override)
7. [Dependencies](#dependencies)
8. [Future Improvements](#future-improvements)

## Overview

The Car System is designed to model the behavior of a car, including its construction, state management, and basic operations such as starting, stopping, driving, and distance tracking.

## Components

### 1. Car Class

The `Car` class is the core component representing a car. It encapsulates the following attributes:

- **make**: The make of the car.
- **model**: The model of the car.
- **engineState**: The current state of the car engine (ON or OFF).
- **totalDistance**: The total distance traveled by the car.

#### Functions:

- **validateParameters**: Validates the input parameters for car initialization, ensuring the make and model are non-empty, and the total distance is non-negative.

- **handleValidationFailure**: Handles the failure of parameter validation. In developer mode, it logs validation failure details, takes corrective actions, and does not propagate the exception.

- **startEngine**: Starts the car engine, provided it is not already ON.

- **stopEngine**: Stops the car engine, provided it is not already OFF.

- **drive**: Drives the car for a specified distance, validating the distance and engine state.

- **showTotalDistance**: Displays the total distance traveled by the car.

- **showEngineState**: Prints the current engine state.

- **showCarDetails**: Prints details about the car (make and model).

- **compareCars**: Compares two cars for equality based on make and model.

- **areCarsEqual**: Checks if two cars are equal based on make and model.

#### Constructors:

- **Default Constructor**: Initializes a car with default values, validates parameters, and logs construction details.

- **Parameterized Constructors**: Allow initialization with different sets of parameters, setting default values for missing parameters. Validate parameters and log construction details.

- **Copy Constructor**: Initializes a car with the same values as another car, validates parameters, and logs construction details.

#### Destructor:

- **Destructor**: Logs destruction details if in developer mode and confidential override is enabled.

#### Inline Getters:

- **getMake**: Returns the make of the car.
- **getModel**: Returns the model of the car.
- **getEngineState**: Returns the engine state (ON or OFF) as a string.
- **getTotalDistance**: Returns the total distance traveled by the car.

### 2. Config Class

The `Config` class is responsible for holding configuration settings, such as developer mode and confidential override.

#### Settings:

- **developerMode**: A boolean flag indicating whether the system is in development mode (true) or production mode (false).

- **confidentialOverride**: A boolean flag allowing confidential override. If true, the system logs destruction details.

### 3. Other Files

- **config.hpp**: Header file containing configuration settings.
- **cmd_functions.hpp**: Header file containing command-related functions.

## Usage

The Car System can be used by instantiating the `Car` class and calling its various functions to interact with the car. Configuration settings can be adjusted using the `Config` class.

## Error Handling

The system employs exception handling to manage errors during car operations. Validation failures are caught, and in developer mode, detailed information is logged.

## Developer Mode

The `Config::developerMode` setting allows developers to enable or disable additional logging and error-handling features.

## Confidential Override

The `Config::confidentialOverride` setting, when enabled, allows the system to log destruction details.

## Dependencies

The system relies on standard C++ libraries for input/output, exception handling, and mathematical operations.

## Future Improvements

Potential areas for improvement include extending functionality (e.g., additional car features), enhancing error handling, and improving configurability.