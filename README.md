# Numerical Precision

- **Description**: A tiny C++ utility demonstrating how to compute the machine (floating-point) precision for `float`, `double`, and `long double`, and to check whether the program is running on a 64-bit architecture.
- **Language**: C++ (requires C++17)

## Features
- **get_machine_precision<T>**: Template that returns the machine precision (epsilon) for a floating-point type `T` (`float`, `double`, `long double`).
- **running_on_64bit_architecture**: Helper that returns `true` when the memory address size is 8 bytes.

## Files of interest
- `src/numerical_precision.hpp`: Header-only implementation of the utilities.
- `src/test_numerical_precision.cxx`: Small executable that prints detected precisions and architecture width.
- `CMakeLists.txt`: Project build configuration using CMake.

## Build (CMake)
1. Create a build directory and run CMake from it:

```bash
mkdir build 
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

2. Common build options (passed to `cmake`):
- `-DBUILD_DEBUG=ON` or set `-DCMAKE_BUILD_TYPE=Debug` to enable debug flags.
- `-DDLL_BUILD=ON` to build as a shared library instead of an executable (maybe ignore for this).

Example debug build:

```bash
mkdir build
cmake -S . -B build -DBUILD_DEBUG=ON
# or
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build build
# or 
cmake --build build --config Debug
```

## Run
After building the executable (default target name is `test-numerical-precision`):

```bash
./test-numerical-precision
```

Sample output (values depend on your platform/compiler):

```bash
Machine precision for float:        1.1920928955078125e-07
Machine precision for double:       2.2204460492503131e-16
Machine precision for long double:  1.0842021724855044e-19

Running on a 64-bit architecture.
Test completed successfully.
```

## API (usage)
Include the header and call the utilities directly:

```cpp
#include "numerical_precision.hpp"

float f_eps = numerical_precision::get_machine_precision<float>();
bool is64 = numerical_precision::running_on_64bit_architecture();
```

--------

**Notes**:
- `get_machine_precision<T>()` requires `T` to be a floating-point type; it uses a shrinking loop to find the smallest `e` such that `1 + e != 1`.
- The implementation is header-only and portable; it relies on the C++ standard library and C++17 features.

**Requirements & Compatibility**
- C++17 compatible compiler (GCC, Clang, MSVC).
- CMake >= 3.16 (as declared in `CMakeLists.txt`).

**License**
This repository includes a `LICENSE` file. Please review it for terms.

**Contributing**
- Fixes, improvements, and suggestions are welcome. Open an issue or submit a pull request describing the change.

**Contact / Author**
- See repository metadata or the `git` history for author information.

