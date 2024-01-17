# Car System Usage Guide

Welcome to the Car System! This guide will walk you through the setup, usage, and some common scenarios when working with the system.

## TABLE OF CONTENTS
1. [System Setup](#system-setup)
2. [Basic Operations](#basic-operations)
   - [Initializing a Car](#initializing-a-car)
   - [Starting and Stopping the Engine](#starting-and-stopping-the-engine)
   - [Driving the Car](#driving-the-car)
   - [Displaying Car Information](#displaying-car-information)
3. [Operating System Configuration](#operating-system-configuration)
4. [Error Handling](#error-handling)
5. [Developer Mode](#developer-mode)
6. [Confidential Override](#confidential-override)
7. [Conclusion](#conclusion)

## SYSTEM SETUP

Before using the Car System, make sure you have the necessary files in your project:

- **`car.hpp`** containing the `Car` class declaration.
- **`config.hpp`** for configuration settings.
- **`cmd_functions.hpp`** for command-related functions.

Ensure that your project is configured to include these files.

## BASIC OPERATIONS

### Initializing a Car

To use the Car System, you need to initialize a `Car` object. The system provides multiple constructors to suit different scenarios:

// Example of initializing a car with default constructor
- `Car myCar;` // Creates a car with default values (make: "Ford", model: "Mustang")

// Example of initializing a car with a parameterized constructor
- `Car customCar("Chevrolet", "Camaro");`

### Starting and Stopping the Engine

Once the car is initialized, you can start and stop the engine:

- `myCar.startEngine();` // Starts the car engine
- `myCar.stopEngine();`  // Stops the car engine

### Driving the Car

Drive the car for a specified distance using the `drive` function:

- `myCar.drive(50.5);` // Drives the car for 50.5 kilometers

### Displaying Car Information

Display information about the car, such as the engine state and total distance:

- `myCar.showEngineState();`    // Prints the current engine state
- `myCar.showTotalDistance();`  // Prints the total distance traveled by the car

## OPERATING SYSTEM CONFIGURATION

The header file `cmd_functions.hpp` manages console configurations tailored for different operating systems. Currently, the setup is available for Windows and Linux/UNIX. Incompatibility with other operating systems is expected, but it doesn't impede the program's execution at this stage.

## ERROR HANDLING

The system employs exception handling for error scenarios. If an error occurs, an appropriate message will be displayed. For example, ensure the engine is ON before driving and provide valid parameters during initialization.

## DEVELOPER MODE

The system includes a developer mode that enhances logging and error-handling features. Developer mode is typically used during development and debugging to provide additional information about the system's internal state. To enable developer mode, set `Config::developerMode` to `true`:

- `Config::developerMode = true;`

## CONFIDENTIAL OVERRIDE

For confidential scenarios, the system can log destruction details. Confidential override allows logging of sensitive information during destruction. To enable confidential override, set `Config::confidentialOverride` to `true`:

- `Config::confidentialOverride = true;`

## CONCLUSION

Congratulations! You've successfully set up and used the Car System. For more advanced usage and additional features, refer to the [architecture.md](architecture.md) document.

If you encounter any issues or have questions, refer to the error messages, review the code, or seek assistance from the development team.

Happy driving!

Feel free to use this content directly or make further modifications as needed.