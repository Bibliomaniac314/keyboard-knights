// Keyboard-knights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PuzzleSolver.h"
using namespace std;

int main()
{
    PuzzleSolver p = PuzzleSolver(10);

    // Find all combinations for each key in the keyboard.
    for (int row = 0; row < keyboard.size(); row++) {
        for (int col = 0; col < sizeof(keyboard[row]); col++) {
            char key = keyboard[row][col];
            p.findCombinationsFromPos(string{ key }, array<int, 2>{row, col});
        }
    }

    // Check all combinations for errors, then print the sum.
    for (string combo : p.combinations) {
        if (combo.length() != 10) {
            cout << "\nERROR! Combination is not correct length! Combination: " << combo << endl;
            break;
        }
        if (p.checkForInvalidVowels(combo)) {
            cout << "\nERROR! Combination has too many vowels! Combination: " << combo << endl;
            break;
        }
        //cout << combo << " ";
    }
    cout << "\n\nTotal Combinations in p: " << p.combinations.size();

}

