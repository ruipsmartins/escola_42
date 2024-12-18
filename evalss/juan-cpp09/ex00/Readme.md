# Exercise 00: Bitcoin Exchange

## Overview

This exercise involves creating a program that outputs the value of a certain amount of Bitcoin on a specified date. The program will utilize a database in CSV format representing Bitcoin prices over time, and take a second database as input, which contains different prices and dates to evaluate.

## Turn-in Directory

ex00/

## Files to Turn In

- `Makefile`
- `main.cpp`
- `BitcoinExchange.{cpp, hpp}`

## Forbidden Functions

- None

## Program Specifications

- **Program Name**: `btc`
- **Input**:
  - The program must take a file as an argument.
  - Each line in this file must use the following format: `"date | value"`.
- **Date Format**:
  - A valid date will always be in the format: `Year-Month-Day`.
- **Value Format**:
  - A valid value must be either a float or a positive integer, between 0 and 1000.

## Instructions

1. **Standard Containers Usage**:
   - Use standard containers from the C++ Standard Template Library (STL) to complete this exercise.
2. **Preliminary Reading**:
   - It is advisable to read the entire subject document before starting the exercise for clarity and strategic planning.
3. **Makefile Requirements**:
   - Provide a Makefile that:
     - Compiles your source files into the required output.
     - Uses the following compiler flags:
       - `-Wall`
       - `-Wextra`
       - `-Werror`
     - Ensures no unnecessary relinking occurs.
   - Mandatory Makefile Rules:
     - `$(NAME)`
     - `all`
     - `clean`
     - `fclean`
     - `re`

## How to Run the Program

1. **Compile the Program**:
   ```sh
   make

   ./btc <input_file>

   ```

May your coding journey be as prosperous as the Bitcoin market! 🚀💰
