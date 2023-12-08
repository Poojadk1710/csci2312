//TODO S-2: include any needed and allowed libraries
#include <iostream>
#include <iomanip>
#include <string>

int main() {

    //TODO S-3: get the sentinel value to be used as an input from the user.
    // use the prompt: "Input the sentinel value:\n"
    int setinel;
    std::cout << "Input the sentinel value:\n" << std::endl;
    std::cin >> sentinel;

    //TODO S-4: ask the user to input a list of numbers. Your program should only give this prompt once.
    //          you can assume the user will only pass in integers as inputs, but you should output an error message if they enter in negative numbers (other than a negative sentinel value).
    // use the prompt: "Input the numbers to be used. Please enter one per line.\n"
    // use the error message: "Sorry, no negative numbers are allowed. Only enter positive numbers!\n"
    int min = 0;
    int max = 0;
    int sum = 0;
    int count = 0;

    // Checks if the user entered sentinel value to exit the loop
    int num;
    while(true){
        std::cin>>num;
        if(count==0){
            min = num;
            max = num;
        }

    }

    if(num == sentinel){
        break;
    }

 if (num == sentinel) {
            break;
        }

        // Check for negative numbers
        if (num < 0) {
            std::cout << "Sorry, no negative numbers are allowed. Only enter positive numbers!\n";
            continue;  // Skips the rest of loop iteration
        }

        // Update min, max, sum, and count
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
        sum += num;
        count++;
    }

    // Calculate average (sum / count)
    double average = static_cast<double>(sum) / count;

    //TODO S-6: Output the resulting values
    // Use the format: "Min value is: <min value>. Max value is: <max value>. Average is: <average>.\n"
    std::cout << "Min value is: " << min << ". Max value is: " << max << ". Average is: " << std::fixed << std::setprecision(2) << average << ".\n";

    return 0;
}