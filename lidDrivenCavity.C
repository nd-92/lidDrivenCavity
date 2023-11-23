// Includes
#include "omegaPsiFormulation.H"
#include "IOControl.H"
#include "scalarArrays.H"
#include "meshTools.H"
#include "runTimeControl.H"

// Dimensions of grid
const arrayLabel meshDim[2] = {51, 51};

// Reynolds number and time step
const scalarVariable Re = 1;
const scalarVariable dt = 1e-8;

// Initialise the solution arrays
scalarArray omega = initialiseScalarArray(meshDim);
scalarArray omega_ = initialiseScalarArray(meshDim);
scalarArray psi = initialiseScalarArray(meshDim);
scalarArray psi_ = initialiseScalarArray(meshDim);

// Initialise the mesh arrays
const scalarArray x = initialiseMeshArray(meshDim, 0);
const scalarArray y = initialiseMeshArray(meshDim, 1);
const scalarArray dx = computeMeshSpacing(x, meshDim, 0);
const scalarArray dy = computeMeshSpacing(y, meshDim, 1);

// Run time control
scalarLine rowMax = initialiseScalarLine(meshDim[0]);
scalarLine currentRow = initialiseScalarLine(meshDim[1]);

// Iteration control
arrayLabel runTimeIterator_ = 0;
const arrayLabel maxIterations_ = 100000000;

// Convergence control
scalarVariable residualError_ = 1;
const scalarVariable solutionTolerance_ = 1e-4;

int main()
{
    // Begin timing of execution
    const scalarVariable startTime = getWallTime();

    // Main solver loop
    while (runTime(runTimeIterator_, maxIterations_, residualError_, solutionTolerance_) == true)
    {
        // Apply boundary conditions to omega
        boundaryConditions(omega, psi, dx, dy, meshDim);

        // Prepare for time integration
        assignPrevious(omega, omega_, meshDim);

        // Time integration
        omegaPsiIntegrator(omega, omega_, psi, psi_, dx, dy, meshDim, dt, Re);

        // Get vorticity residual
        getResidual(residualError_, omega, omega_, meshDim, rowMax, currentRow);
        printScalarVariable(residualError_);

        // Advance iterator
        runTimeIterator_++;
    }

    // Finish timing of execution
    const scalarVariable endTime = getWallTime();

    // Print elapsed time to terminal
    printElapsedTime(startTime, endTime);

    // Recover velocity
    scalarArray u = initialiseScalarArray(meshDim);
    scalarArray v = initialiseScalarArray(meshDim);
    streamFunctionToVelocity(u, v, psi, dx, dy, meshDim);

    // Write solution to file
    writeScalarArray("omega", omega, meshDim);
    writeScalarArray("psi", psi, meshDim);
    writeScalarArray("u", u, meshDim);
    writeScalarArray("v", v, meshDim);

    return 0;
}
