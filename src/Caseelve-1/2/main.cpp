#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int main() {
    const unsigned int MAX_GRADES{ 5 }; // Number of grades to read
    std::vector<unsigned int> grades(MAX_GRADES); // Stores the user grades
    std::vector<unsigned int> histogram(10, 0); // Store the histogram

    std::string inputFileName;
    std::cout << "Enter input filename: ";
    std::cin >> inputFileName;

    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error opening file " << inputFileName << std::endl;
        return 1;
    }

    for (size_t index{ 0 }; index < MAX_GRADES; ++index) {
        if (!(inputFile >> grades[index])) {
            std::cerr << "Error reading grades from file." << std::endl;
            return 1;
        }
    }

    inputFile.close();

    // Sum and Average
    int sum{ 0 };
    float avg{ 0.0 };
    for (size_t index{ 0 }; index < MAX_GRADES; ++index) {
        std::cout << grades[index] << " | ";
        sum += grades[index];
    }
    std::cout << std::endl;
    avg = static_cast<float>(sum) / MAX_GRADES;
    std::cout << "The grade sum is: " << sum << std::endl;
    std::cout << "The grade avg is: " << avg << std::endl;

    // Compute histogram
    for (int index{ 0 }; index < MAX_GRADES; ++index) {
        unsigned int gradeBucket{ 0 };

        if (grades[index] >= 100)
            gradeBucket = 9; //last percentile
        else
            gradeBucket = grades[index] / 10;  // 95 -> 9, 55 -> 5

        histogram[gradeBucket]++;
    }

    // Display Histogram
    std::ofstream outputFile(inputFileName + ".RPT");
    if (!outputFile) {
        std::cerr << "Error creating output file." << std::endl;
        return 1;
    }

    for (int bucket{ 0 }; bucket < 10; ++bucket) {
        outputFile << std::setw(2) << bucket << ":";
        for (int i{ 0 }; i < histogram[bucket]; ++i)
            outputFile << "|";
        outputFile << std::endl;
    }

    outputFile.close();

    return 0;
}