//a program that generates a random number and asks the
//user to guess it

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;
    std::cout << "Try to guess it!" << std::endl;

    // Loop until the user guesses the correct number
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        // Check the guess
        if (guess < randomNumber) {
            std::cout << "Your guess is too low. Try again!" << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Your guess is too high. Try again!" << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number " 
                      << randomNumber << " in " << attempts << " attempts." << std::endl;
            break; // Exit the loop
        }
    }

    return 0;
}