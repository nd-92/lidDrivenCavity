#include "scalarArrays.H"

scalarArray initialiseScalarArray(
    const arrayLabel meshDim[2])
{
    // Allocate and set to 0
    scalarArray f(meshDim[0], scalarLine(meshDim[1], 0));

    return f;
}

scalarLine initialiseScalarLine(
    const arrayLabel dim)
{
    // Allocate and set to 0
    scalarLine f(dim, 0);

    return f;
}