/TODO C-2: include any needed and *allowed* libraries


#include <iostream>
#include <iomanip>
#include <string>

int main() {

    //TODO C-3: Get the total number of values to be read as inputs from the user.
    // Use the prompt: "Input the total number of values:\n"
    int totalValues;
    std::cout << "Input the total number of values:\n";
    std::cin >> totalValues;

    //TODO C-4: Ask the user to input a list of numbers. Your program should only give this prompt once.
    // You can assume the user will only pass in integers as inputs, but you should output an error message if they enter negative numbers.
    // Use the prompt: "Input the numbers to be used. Please enter one per line.\n"
    // Use the error message: "Sorry, no negative numbers are allowed. Only enter positive numbers!\n"
    std::cout << "Input the numbers to be used. Please enter one per line.\n";

    int min = 0;  // Initialization min with a large value
    int max = 0;  // Initialization max with a small value
    int sum = 0;
    int count = 0;

    for (int i = 0; i < totalValues; ++i) {
        int num;
        std::cin >> num;
        if (count == 0){
            min = num;
            max = num;
        }

        // Check for negative numbers
        if (num < 0) {
            std::cout << "Sorry, no negative numbers are allowed. Only enter positive numbers!\n";
            // Decrements the loop counter to allow the user to re-enter a valid number
            --i;
            continue;  // Skips the rest of the loop iteration
        }

        // Update min, max, and sum
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
        sum += num;
        count++;
    }

    // Calculate the average (sum / totalValues)
    double average = static_cast<double>(sum) / totalValues;

    //TODO C-6: Output the resulting values
    // Use the format: "Min value is: <min value>. Max value is: <max value>. Average is: <average>.\n"
    std::cout << "Min value is: " << min << ". Max value is: " << max << ". Average is: " << std::fixed << std::setprecision(2) << average << ".\n";

    return 0;
}