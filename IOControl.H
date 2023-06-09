#ifndef IOControl_H
#define IOControl_H

#include "globalHeader.H"

void printScalarArray(
    const scalarArray &f,
    const arrayLabel meshDim[2]);

inline void printElapsedTime(
    const scalarVariable &startTime,
    const scalarVariable &endTime)
{
    scalarVariable elapsedTime = endTime - startTime;
    std::cout << "Main solver loop elapsed time: " << elapsedTime << " seconds" << endl;
}

inline void printScalarVariable(
    const scalarVariable f)
{
    cout << setprecision(15) << f << endl;
}

#endif
