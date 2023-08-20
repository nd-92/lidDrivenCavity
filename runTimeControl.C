#include "runTimeControl.H"

arrayLabel runTimeIterator = 0;
scalarVariable residualError = 1;

bool runTime(
    const arrayLabel &i,
    const arrayLabel &maxIterations,
    const scalarVariable &residualError,
    const scalarVariable &solutionTolerance)
{
    // Continue run time if i is less than max iterations and solution has not converged
    if (i < maxIterations && residualError > solutionTolerance)
    {
        return true;
    }
    // Otherwise end run time
    else
    {
        return false;
    }
}

scalarVariable getWallTime()
{
    struct timeval time;
    if (gettimeofday(&time, NULL))
    {
        return 0;
    }
    else
    {
        return scalarVariable(time.tv_sec) + scalarVariable(time.tv_usec) * .000001;
    }
}

void getResidual(
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
