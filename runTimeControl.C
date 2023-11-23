#include "runTimeControl.H"

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
