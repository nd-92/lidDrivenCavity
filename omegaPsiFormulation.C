#include "omegaPsiFormulation.H"

void streamFunctionToVelocity(
    scalarArray &u,
    scalarArray &v,
    const scalarArray &psi,
    const scalarArray &dx,
    const scalarArray &dy,
    const arrayLabel meshDim[2])
{
    // Assign interior points
    for (arrayLabel i = 1; i < meshDim[0] - 1; i++)
    {
        for (arrayLabel j = 1; j < meshDim[1] - 1; j++)
        {
            u[i][j] = (psi[i][j + 1] - psi[i][j - 1]) / (2 * dy[i][j]);
            v[i][j] = -(psi[i + 1][j] - psi[i - 1][j]) / (2 * dx[i][j]);
        }
    }

    // Top boundary
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        u[i][meshDim[1] - 1] = 1;
        v[i][meshDim[1] - 1] = 0;
    }

    // Bottom boundary
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        u[i][0] = 0;
        v[i][0] = 0;
    }

    // Left boundary
    for (arrayLabel j = 0; j < meshDim[1]; j++)
    {
        u[0][j] = 0;
        v[0][j] = 0;
    }

    // Right boundary
    for (arrayLabel j = 0; j < meshDim[1]; j++)
    {
        u[meshDim[0] - 1][j] = 0;
        v[meshDim[0] - 1][j] = 0;
    }
}
