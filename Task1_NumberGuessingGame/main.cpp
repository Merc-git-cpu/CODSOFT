#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main(){ 

    vector<int> nums;

    for (int i = 1; i <= 100; i++) {
        nums.push_back(i);
    }
  
    random_device rd;
    mt19937 gen(rd());
    shuffle(nums.begin(), nums.end(), gen);
    int secretNumber = nums[0];

    int guess, attempts = 0;

    cout << "========== NUMBER GUESSING GAME ==========" << endl;
    cout << "Guess a number between 1 and 100." << endl;

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > secretNumber) {
            cout << "Too High! Try Again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too Low! Try Again." << endl;
        }
        else {
            cout << "\nCongratulations! You guessed the correct number." << endl;
            cout << "Secret Number: " << secretNumber << endl;
            cout << "Attempts: " << attempts << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
