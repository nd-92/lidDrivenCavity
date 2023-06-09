#ifndef meshTools_H
#define meshTools_H

#include "globalHeader.H"
#include "scalarArrays.H"

scalarArray initialiseMeshArray(
    const arrayLabel meshDim[2],
    const arrayLabel dir);

void computeMeshSpacing(
    scalarArray &gridSpacing,
    const scalarArray &grid,
    const arrayLabel meshDim[2],
    const arrayLabel dir);

#endif