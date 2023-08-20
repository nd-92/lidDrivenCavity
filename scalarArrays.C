#include "scalarArrays.H"

scalarArray initialiseScalarArray(
    const arrayLabel meshDim[2])
{
    // Allocate and set to 0
    const scalarArray f(meshDim[0], scalarLine(meshDim[1], 0));

    return f;
}

scalarLine initialiseScalarLine(
    const arrayLabel dim)
{
    // Allocate and set to 0
    const scalarLine f(dim, 0);

    return f;
}