#include "meshTools.H"

const scalarArray initialiseMeshArray(
    const arrayLabel meshDim[2],
    const bool dir)
{
    // Create the array of all zeros
    scalarArray grid = initialiseScalarArray(meshDim);

    // Compute mesh points in x direction if dir = 0
    if (dir == false)
    {
        for (arrayLabel i = 0; i < meshDim[0]; i++)
        {
            for (arrayLabel j = 0; j < meshDim[1]; j++)
            {
                grid[i][j] = scalarVariable(i) / scalarVariable(meshDim[0] - 1);
            }
        }
    }
    // Compute mesh points in y direction if dir = 1
    else
    {
        for (arrayLabel i = 0; i < meshDim[0]; i++)
        {
            for (arrayLabel j = 0; j < meshDim[1]; j++)
            {
                grid[i][j] = scalarVariable(j) / scalarVariable(meshDim[1] - 1);
            }
        }
    }

    return grid;
}

const scalarArray computeMeshSpacing(
    const scalarArray &grid,
    const arrayLabel meshDim[2],
    const bool dir)
{
    // Create the array of all zeros
    scalarArray gridSpacing = initialiseScalarArray(meshDim);

    // Compute central difference in x direction if dir = 0
    if (dir == 0)
    {
        // Boundary points
        for (arrayLabel j = 0; j < meshDim[1]; j++)
        {
            gridSpacing[0][j] = grid[1][j] - grid[0][j];
            gridSpacing[meshDim[0] - 1][j] = grid[meshDim[0] - 1][j] - grid[meshDim[0] - 2][j];
        }
        // Interior points
        for (arrayLabel i = 1; i < meshDim[0] - 1; i++)
        {
            for (arrayLabel j = 0; j < meshDim[1]; j++)
            {
                gridSpacing[i][j] = 0.5 * (grid[i + 1][j] - grid[i - 1][j]);
            }
        }
    }
    // Compute central difference in y direction if dir = 1
    else
    {
        // Boundary points
        for (arrayLabel i = 0; i < meshDim[0]; i++)
        {
            gridSpacing[i][0] = grid[i][1] - grid[i][0];
            gridSpacing[i][meshDim[1] - 1] = grid[i][meshDim[1] - 1] - grid[i][meshDim[1] - 2];
        }
        // Interior points
        for (arrayLabel i = 0; i < meshDim[0]; i++)
        {
            for (arrayLabel j = 1; j < meshDim[1] - 1; j++)
            {
                gridSpacing[i][j] = 0.5 * (grid[i][j + 1] - grid[i][j - 1]);
            }
        }
    }

    return gridSpacing;
}