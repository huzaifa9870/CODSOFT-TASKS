#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator
    int randomNumber = rand() % 100 + 1; // Generate random number between 1 and 100
    int guess;

    cout << "Welcome to the Number Guessing Game!\n\n";

    do {
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;

        if (guess < randomNumber) {
            cout << "Too low. Try again.\n";
        } else if (guess > randomNumber) {
            cout << "Too high. Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number.\n";
        }
    } while (guess != randomNumber);

    return 0;
}
