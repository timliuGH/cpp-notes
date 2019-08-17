/******************************************************************************
 * The function repeatArray takes an array and its size and doubles the 
 * capacity.
******************************************************************************/
#include <iostream>

void repeatArray(double *&array, int arraySize)
{
    // Create new array with double the size.
    double *newArray = new double[arraySize * 2];

    // Fill new array with original array's contents twice.
    int newArrayIndex = 0;
    for (int i = 0; i < 2; i++)
        for (int i = 0; i < arraySize; i++)
        {
            newArray[newArrayIndex] = array[i];
            newArrayIndex++;
        }

    // Re-assign original array to new array.
    delete [] array;
    array = newArray;
}

int main()
{
    int initialArraySize = 3;
    double *myArray = new double[initialArraySize];
    for (int i = 0; i < initialArraySize; i++)
        myArray[i] = (i+1)*2;

    std::cout << "original array: ";
    for (int i = 0; i < initialArraySize; i++)
        std::cout << myArray[i] << " ";
    std::cout << std::endl;

    repeatArray(myArray, initialArraySize);

    std::cout << "new array: ";
    for (int i = 0, end = initialArraySize * 2; i < end; i++)
        std::cout << myArray[i] << " ";
    std::cout << std::endl;

    delete [] myArray;
    myArray = NULL;

    return 0;
}
