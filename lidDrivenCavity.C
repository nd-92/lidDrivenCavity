#include "omegaPsiFormulation.H"
#include "IOControl.H"
#include "scalarArrays.H"
#include "meshTools.H"
#include "runTimeControl.H"

// Dimensions of grid
const arrayLabel meshDim[2] = {101, 101};

// Some parameters
const scalarVariable Re = 1;
const scalarVariable dt = 0.00001;

// Initialise the solution arrays
scalarArray omega = initialiseScalarArray(meshDim);
scalarArray omega_ = initialiseScalarArray(meshDim);
scalarArray psi = initialiseScalarArray(meshDim);
scalarArray psi_ = initialiseScalarArray(meshDim);

// Initialise the mesh arrays
scalarArray x = initialiseMeshArray(meshDim, 1);
scalarArray y = initialiseMeshArray(meshDim, 2);
scalarArray dx = initialiseScalarArray(meshDim);
scalarArray dy = initialiseScalarArray(meshDim);

// Initialise the convergence control arrays
scalarLine rowMax = initialiseScalarLine(meshDim[0]);
scalarLine currentRow = initialiseScalarLine(meshDim[1]);

int main()
{
    // Get finite difference grid spacing
    computeMeshSpacing(dx, x, meshDim, 1);
    computeMeshSpacing(dy, y, meshDim, 2);

    // Begin timing of execution
    scalarVariable startTime = getWallTime();

    // Main solver loop
    while (runTime(runTimeIterator, maxIterations, residualError, solutionTolerance) == true)
    {
        // Apply boundary conditions to omega
        boundaryConditions(omega, psi, dx, dy, meshDim);

        // Prepare for time integration
        assignPrevious(omega, omega_, meshDim);
        assignPrevious(psi, psi_, meshDim);

        // Time integration
        omegaPsiIntegrator(omega, omega_, psi, psi_, dx, dy, meshDim, dt, Re);

        // Get vorticity residual
        getResidual(residualError, omega, omega_, meshDim, rowMax, currentRow);
        printScalarVariable(residualError);

        // Advance iterator
        runTimeIterator++;
    }

    // Finish timing of execution
    scalarVariable endTime = getWallTime();

    // Print elapsed time to terminal
    printElapsedTime(startTime, endTime);

    return 0;
}
