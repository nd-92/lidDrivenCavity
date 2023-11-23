#ifndef runTimeControl_H
#define runTimeControl_H

#include "globalHeader.H"

inline bool runTime(
    const arrayLabel &i,
    const arrayLabel &maxIterations,
    const scalarVariable &residualError,
    const scalarVariable &solutionTolerance)
{
    return (i < maxIterations && residualError > solutionTolerance);
}

scalarVariable getWallTime();

inline void getResidual(
    scalarVariable &residualError,
    const scalarArray &f,
    const scalarArray &f_,
    const arrayLabel meshDim[2],
    scalarLine &rowMax,
    scalarLine &currentRow)
{
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        for (arrayLabel j = 0; j < meshDim[1]; j++)
        {
            currentRow[j] = fabs(f[i][j] - f_[i][j]);
        }
        rowMax[i] = *max_element(currentRow.begin(), currentRow.end());
    }
    residualError = *max_element(rowMax.begin(), rowMax.end());
}

#endif
