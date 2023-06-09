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
