# Car System Project (version 4)

This project represents a comprehensive car simulation system with various versions, each introducing specific features and improvements.

## Table of Contents
1. [Important Dev Note](#important-dev-note)
2. [Building](#building)
3. [Features](#features)
4. [Build Artifacts](#build-artifacts)
5. [Common Headers](#common-headers)
6. [License](#license)
7. [Improvements/Adjustments from Previous Versions](#improvementsadjustments-from-previous-versions)
8. [Future Versions (To-Do List)](#future-versions-to-do-list)

## Important Dev Note

Please note that my project is on an early stage, and thus I haven't had the time to make a menu yet (meaning that my `main.cpp` is a little bit messy and that I get to choose what you'll do in the program). The good news is the menu is coming in the upcoming version so be just a little bit patient! :)

## Building

To build the Version 4 executable, navigate to the `version_4/build/run` directory and run the `run.exe` file.

## Features

- Initializing a Car
- Starting and Stopping the Engine
- Driving the Car
- Displaying Car Information
- Error Handling
- Developer Mode
- Confidential Override

## Common Headers

The `common_headers` directory contains header files shared across all versions.

## Build Artifacts

Build artifacts, including executables and DLLs, are located in the `build` directories within each version.

Feel free to explore the source code in the `src` and `include` directories for each version.

## License

This project is licensed under the [License Name] - see the [LICENSE.md](LICENSE.md) file for details.

## Improvements/Adjustments from Previous Versions

- Enhanced error handling for smoother user experience.
- Improved configurability with the `Config` class.
- Operating system-specific console configurations in `cmd_functions.hpp`.
- Detailed [architecture](architecture.md) of the `Car` class and system components.
- Added a compehensive [usage guide](usage_guide.md) for better understanding and utilization of the Car System.

## Future Versions (To-Do List)

- Extend functionality with additional car features (accelerate, break)
- Add physics (at least friction).
- Add a user menu.
- Enhance error handling further.
- Improve configurability and flexibility.
- Explore additional operating system compatibility.
- Any other future improvements based on project requirements.
- I will be adding cmake/catch2 tests (maybe a little bit far) in the future

Feel free to contribute, report issues, or suggest enhancements to make the Car System even better!
