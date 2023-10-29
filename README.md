# Fraction Manipulation Library

This C library provides a set of functions for working with fractions. It allows you to perform various operations on fractions, including addition, subtraction, multiplication, division, exponentiation, square root, and more.

## Table of Contents
- [Overview](#overview)
- [Functions](#functions)
- [Usage](#usage)
- [Examples](#examples)

## Overview

This library is designed to handle fractional calculations efficiently. It includes functions to create fractions, manipulate their numerator and denominator, perform arithmetic operations, and simplify fractions.

## Functions

### Fraction* Fraction_Create()

Create a new fraction with an initial value of 0.

### void Fraction_Free(Fraction *f)

Free the memory allocated for a fraction.

### void Fraction_SetNum(Fraction *f, double value)

Set the numerator of the fraction with a double value.

### int Fraction_GetNum(Fraction *f)

Get the numerator of the fraction.

### void Fraction_SetDen(Fraction *f, double value)

Set the denominator of the fraction with a double value.

### int Fraction_GetDen(Fraction *f)

Get the denominator of the fraction.

### void Fraction_SetValue(Fraction *f, double value)

Set the fraction's value with a double.

### double Fraction_GetValue(Fraction *f)

Get the value of the fraction as a double.

### Fraction Fraction_Sum(Fraction *f1, Fraction *f2)

Add two fractions and return the result as a simplified fraction.

### Fraction Fraction_Sub(Fraction *f1, Fraction *f2)

Subtract two fractions and return the result as a simplified fraction.

### Fraction Fraction_Mul(Fraction *f1, Fraction *f2)

Multiply two fractions and return the result as a simplified fraction.

### Fraction Fraction_Div(Fraction *f1, Fraction *f2)

Divide two fractions and return the result as a simplified fraction.

### Fraction Fraction_Pow(Fraction *f, int p)

Raise a fraction to a power and return the result as a simplified fraction.

### Fraction Fraction_Sqrt(Fraction *f)

Calculate the square root of a fraction and return the result as a simplified fraction.

### void Fraction_Reduce(Fraction *f)

Simplify a fraction to its lowest terms.

### int Fraction_IsInteger(Fraction *f)

Check if a fraction is an integer (i.e., its value is a whole number).

### int PGCD(int a, int b)

Calculate the greatest common divisor (GCD) of two integers.

## Usage

To use this library in your C project, follow these steps:

1. Include the `fraction.h` header in your C source file.
   
   ```c
   #include "fraction.h"
   ```
Make sure you have linked the library with your project during compilation.

gcc -o your_program your_program.c fraction.c -lm
```
Use the provided functions to work with fractions in your C code.

Examples
Here are some usage examples of the fraction manipulation functions:
```c
// Create fractions
Fraction *frac1 = Fraction_Create();
Fraction *frac2 = Fraction_Create();

// Set numerator and denominator
Fraction_SetNum(frac1, 2.5);
Fraction_SetDen(frac2, 3);

// Perform arithmetic operations
Fraction result = Fraction_Sum(frac1, frac2);
Fraction result2 = Fraction_Mul(frac1, frac2);

// Print the results
printf("Sum: %d/%d\n", Fraction_GetNum(&result), Fraction_GetDen(&result));
printf("Product: %d/%d\n", Fraction_GetNum(&result2), Fraction_GetDen(&result2));

// Free memory
Fraction_Free(frac1);
Fraction_Free(frac2);
```
Feel free to adapt and use these functions in your C programs for efficient fraction handling.
