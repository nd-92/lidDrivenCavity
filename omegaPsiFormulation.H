#ifndef omegaPsiFormulation_H
#define omegaPsiFormulation_H

#include "globalHeader.H"

void boundaryConditions(
    scalarArray &omega,
    const scalarArray &psi,
    const scalarArray &dx,
    const scalarArray &dy,
    const arrayLabel meshDim[2]);

void assignPrevious(
    const scalarArray &f,
    scalarArray &f_,
    const arrayLabel meshDim[2]);

void omegaPsiIntegrator(
    scalarArray &omega,
    const scalarArray &omega_,
    scalarArray &psi,
    const scalarArray &psi_,
    const scalarArray &dx,
    const scalarArray &dy,
    const arrayLabel meshDim[2],
    const scalarVariable &dt,
    const scalarVariable &Re);

#endif
