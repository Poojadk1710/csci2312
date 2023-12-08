#include <iostream>
#include <fstream>
#include <vector>
#include "Time.h"



int main() {

    std::vector<Time*> times;

    std::string inputFilename = "input.txt";
    std::string outputFilename;


       std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << inputFilename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        Time* newTime = new Time();
        newTime->load(line);
        times.push_back(newTime);
    }
    inputFile.close();

    std::cout << "Enter output filename: ";
    std::cin >> outputFilename;

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << outputFilename << std::endl;
        return 1;
    }


    for (const auto& t : times) {
        int hours = t->getHours();
        outputFile << t->toUniversalStandard() << " ";
        outputFile << ((hours < 12) ? "AM" : "PM") << "\t";
        outputFile << *t << std::endl;
        delete t; // Free allocated memory
    }
    outputFile.close();

    return 0;
}