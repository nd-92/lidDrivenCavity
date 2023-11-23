#ifndef meshTools_H
#define meshTools_H

#include "globalHeader.H"
#include "scalarArrays.H"

const scalarArray initialiseMeshArray(
    const arrayLabel meshDim[2],
    const bool dir);

const scalarArray computeMeshSpacing(
    const scalarArray &grid,
    const arrayLabel meshDim[2],
    const bool dir);

#endif