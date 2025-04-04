//Simple Calculator which performs arithmatic operations
#include <iostream>

void displayMenu() {
    
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1. Addition (+)" << std::endl;
    std::cout << "2. Subtraction (-)" << std::endl;
    std::cout << "3. Multiplication (*)" << std::endl;
    std::cout << "4. Division (/)" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "======================" << std::endl;
}

int main() {
    double num1, num2;
    int choice;

    while (true) {
        displayMenu();
        
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        // Exit the program if the user chooses 5
        if (choice == 5) {
            std::cout << "Thank you for using the calculator! Goodbye!" << std::endl;
            break;
        }

        // Input validation for choice
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice. Please select a valid operation." << std::endl;
            continue;
        }

        // Get the numbers from the user
        std::cout << "Enter the first number: ";
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;

        // Perform the chosen operation
        switch (choice) {
            case 1: // Addition
                std::cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
                break;
            case 2: // Subtraction
                std::cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
                break;
            case 3: // Multiplication
                std::cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
                break;
            case 4: // Division
                if (num2 != 0) {
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
                } else {
                    std::cout << "Error: Division by zero is not allowed!" << std::endl;
                }
                break;
            default:
                std::cout << "Something went wrong. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl; // Print a new line for better readability
    }

    return 0;
}