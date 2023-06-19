#ifndef globalHeader_H
#define globalHeader_H

// Required includes
#include <stdio.h>
#include <vector>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <chrono>
#include <time.h>
#include <iomanip>
#include <sys/time.h>
#include <algorithm>

// Required parts of std namespace
using std::vector,
    std::cout,
    std::endl,
    std::setprecision,
    std::max_element,
    std::ofstream,
    std::string,
    std::fixed;

// Typedef for array index integers
typedef uint32_t arrayLabel;

// Typedef for floating point numbers
typedef double scalarVariable;

// Typedef for floating point arrays
typedef vector<vector<scalarVariable>> scalarArray;

// Typedef for lines of floating point arrays
typedef vector<scalarVariable> scalarLine;

#endif