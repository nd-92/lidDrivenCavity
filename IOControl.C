#include "IOControl.H"

void printScalarArray(
    const scalarArray &f,
    const arrayLabel meshDim[2])
{
    //  Loop over all indices printing value of array
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        for (arrayLabel j = 0; j < meshDim[1]; j++)
        {
            printf("%0.15f ", f[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void writeScalarArray(
    const string fileName,
    const scalarArray &f,
    const arrayLabel meshDim[2])
{
    // Open .dat file and set write precision
    ofstream toWrite;
    const string writeName = "solution/" + fileName + ".dat";
    toWrite.open(writeName);
    toWrite << setprecision(100);

    // Loop over all indices printing value of array
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        for (arrayLabel j = 0; j < meshDim[1]; j++)
        {
            toWrite << f[i][j] << " ";
        }
        toWrite << endl;
    }
    toWrite << endl;

    // Close file
    toWrite.close();
}