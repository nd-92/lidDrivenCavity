#ifndef omegaPsiFormulation_H
#define omegaPsiFormulation_H

#include "globalHeader.H"

inline void boundaryConditions(
    scalarArray &omega,
    const scalarArray &psi,
    const scalarArray &dx,
    const scalarArray &dy,
    const arrayLabel meshDim[2])
{
    // Top boundary
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        omega[i][meshDim[1] - 1] = (-2 * psi[i][meshDim[1] - 2] / (pow(dy[i][meshDim[1] - 1], 2))) - (2 / dy[i][meshDim[1] - 1]);
    }

    // Bottom boundary
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        omega[i][0] = -2 * psi[i][1] / (pow(dy[i][0], 2));
    }

    // Left boundary
    for (arrayLabel j = 0; j < meshDim[1]; j++)
    {
        omega[0][j] = -2 * psi[1][j] / (pow(dx[0][j], 2));
    }

    // Right boundary
    for (arrayLabel j = 0; j < meshDim[1]; j++)
    {
        omega[meshDim[0] - 1][j] = -2 * psi[meshDim[0] - 2][j] / (pow(dx[meshDim[0] - 1][j], 2));
    }
}

inline void assignPrevious(
    const scalarArray &f,
    scalarArray &f_,
    const arrayLabel meshDim[2])
{
    // Loop all over indices setting previous value of array
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        for (arrayLabel j = 0; j < meshDim[1]; j++)
        {
            f_[i][j] = f[i][j];
        }
    }
}

inline void omegaPsiIntegrator(
    scalarArray &omega,
    const scalarArray &omega_,
    scalarArray &psi,
    const scalarArray &psi_,
    const scalarArray &dx,
    const scalarArray &dy,
    const arrayLabel meshDim[2],
    const scalarVariable &dt,
    const scalarVariable &Re)
{
    // Time integration of vorticity
    for (arrayLabel i = 1; i < meshDim[0] - 1; i++)
    {
        for (arrayLabel j = 1; j < meshDim[1] - 1; j++)
        {
            omega[i][j] = ((((1 / Re)                                                                               //
                             * (((omega_[i + 1][j] - (2 * omega_[i][j]) + omega_[i - 1][j]) / pow(dx[i][j], 2))     //
                                + ((omega_[i][j + 1] - (2 * omega_[i][j]) + omega_[i][j - 1]) / pow(dy[i][j], 2)))) //
                            - ((((psi_[i][j + 1] - psi_[i][j - 1]) / (2 * dy[i][j]))                                //
                                * ((omega_[i + 1][j] - omega_[i - 1][j]) / (2 * dx[i][j])))                         //
                               + ((-(psi_[i + 1][j] - psi_[i - 1][j]) / (2 * dx[i][j]))                             //
                                  * ((omega_[i][j + 1] - omega_[i][j - 1]) / (2 * dy[i][j])))))                     //
                           * dt) +
                          omega_[i][j]; //
        }
    }

    // Update stream function to new time
    for (arrayLabel i = 1; i < meshDim[0] - 1; i++)
    {
        for (arrayLabel j = 1; j < meshDim[1] - 1; j++)
        {
            psi[i][j] = 0.25 * ((omega[i][j] * (dx[i][j] * dy[i][j])) + psi_[i + 1][j] + psi_[i - 1][j] + psi_[i][j + 1] + psi_[i][j - 1]);
        }
    }
}

void streamFunctionToVelocity(
    scalarArray &u,
    scalarArray &v,
    const scalarArray &psi,
    const scalarArray &dx,
    const scalarArray &dy,
    const arrayLabel meshDim[2]);

#endif
