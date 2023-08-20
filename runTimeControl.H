#ifndef runTimeControl_H
#define runTimeControl_H

#include "globalHeader.H"

// Iteration control
extern arrayLabel runTimeIterator;
static const arrayLabel maxIterations = 100000000;
// static const arrayLabel maxIterations = 1000;

// Convergence control
extern scalarVariable residualError;
static const scalarVariable solutionTolerance = 1e-6;

bool runTime(
    const arrayLabel &i,
    const arrayLabel &maxIterations,
    const scalarVariable &residualError,
    const scalarVariable &solutionTolerance);

scalarVariable getWallTime();

void getResidual(
    scalarVariable &residualError,
    const scalarArray &f,
    const scalarArray &f_,
    const arrayLabel meshDim[2],
    scalarLine &rowMax,
    scalarLine &currentRow);

#endif
