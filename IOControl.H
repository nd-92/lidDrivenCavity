#ifndef IOControl_H
#define IOControl_H

#include "globalHeader.H"

void printScalarArray(
    const scalarArray &f,
    const arrayLabel meshDim[2]);

void writeScalarArray(
    const string fileName,
    const scalarArray &f,
    const arrayLabel meshDim[2]);

inline void printElapsedTime(
    const scalarVariable &startTime,
    const scalarVariable &endTime)
{
    const scalarVariable elapsedTime = endTime - startTime;
    std::cout << "Main solver loop elapsed time: " << elapsedTime << " seconds" << endl;
}

inline void printScalarVariable(
    const scalarVariable f)
{
    printf("%0.15f\n", f);
}

#endif
