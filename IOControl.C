#include "IOControl.H"

void printScalarArray(
    const scalarArray &f,
    const arrayLabel meshDim[2])
{
    // Loop over all indices printing value of array
    for (arrayLabel i = 0; i < meshDim[0]; i++)
    {
        for (arrayLabel j = 0; j < meshDim[1]; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void writeScalarArray(
    const string fileName,
    const scalarArray &f,
    const arrayLabel meshDim[2])
{
    ofstream toWrite;
    toWrite.open(fileName);
    toWrite << setprecision(100);
    for (unsigned i = 0; i < meshDim[0]; i++)
    {
        for (unsigned j = 0; j < meshDim[1]; j++)
        {
            toWrite << f[i][j] << " ";
        }
        toWrite << endl;
    }
    toWrite.close();
}