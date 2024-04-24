# monte_carlo

This project uses a Monte Carlo simulation to approximate the value of Pi.

## Structure

The project is structured as follows:

- `main.cc`: The main entry point of the application.
- `libs/montecarlo.hpp`: The header file for the Monte Carlo simulation class.
- `src/montecarlo.cc`: The implementation of the Monte Carlo simulation class.

## Usage

When you run the program, you will be prompted to either:

1. Define the amount of pseudo-randomly generated values.
2. Define the decimal precision threshold.

After making your selection and providing the necessary input, the simulation will run and output the approximated value of Pi.

## Building

To build the project, use your preferred C++ compiler and include all `.cc` and `.hpp` files.

```bash
g++ main.cc ./src/*.cc -Ilibs/ -std=c++20
# alternatively, you can use -std=c++23 flag
```
