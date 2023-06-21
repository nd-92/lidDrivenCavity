#ifndef meshTools_H
#define meshTools_H

#include "globalHeader.H"
#include "scalarArrays.H"

scalarArray initialiseMeshArray(
    const arrayLabel meshDim[2],
    const bool dir);

scalarArray computeMeshSpacing(
    const scalarArray &grid,
    const arrayLabel meshDim[2],
    const bool dir);

#endif