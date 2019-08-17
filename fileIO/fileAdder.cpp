/******************************************************************************
 * This program serves as a simple example of file I/O in C++.
 *
 * This program gets a file from the user which consists of a list of ints and
 * outputs the sum of the ints to another file.
******************************************************************************/
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // Prompt user for filename.
    std::cout << "Please enter your filename." << std::endl;
    std::string inputFilename;
    std::cin >> inputFilename;

    // Open file and ensure file can be opened.
    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile)
    {
        std::cout << inputFilename << " cannot be opened." << std::endl;
        std::cout << "Program terminating.." << std::endl;
        return 1;
    }

    // Sum values from file.
    int sum = 0;
    int nextFileValue;
    while (inputFile >> nextFileValue)
        sum += nextFileValue;

    inputFile.close();

    // Output sum to fileAdderOutput.txt.
    std::ofstream outputFile("fileAdderOutput.txt");
    outputFile << sum << '\n';
    outputFile.close();

    std::cout << "result written to fileAdderOutput.txt" << std::endl;

    return 0;
}
