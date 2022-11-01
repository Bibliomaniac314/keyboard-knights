// Keyboard-knights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PuzzleSolver.h"
#include <iostream>
#include <list>
using namespace std;

int main()
{
    PuzzleSolver p = PuzzleSolver{};
    
    ////for (auto& row : keyboard) {
    //for (int row = 0; row < keyboard.size(); row++) {
    //    for (int col = 0; col < keyboard[row].size(); col++) {
    //        char key = keyboard[row][col];
    //        cout << "Finding all combos for Key " << key;
    //        p.findCombinationsFromPos(string{ key }, array<int, 2>{0, 0});//{row, col});
    //    }
    //}

    PuzzleSolver p2 = PuzzleSolver{};

    //for (auto& row : keyboard) {
    for (int row = 0; row < keyboard.size(); row++) {
        for (int col = 0; col < sizeof(keyboard[row]); col++) {
            char key = keyboard[row][col];
            cout << "Finding all combos for Key " << key;
            p2.findCombinationsFromPos(string{ key }, array<int, 2>{row, col});
        }
    }

    //Check and print all combinations
    list<string> p2Copies = list<string>{};
    //int p2Copies = 0;
    string lastCombo = "";
    //for (string combo : p.combinations) {
    //    if (combo.length() != 10) {
    //        cout << "\nERROR! Combination is not correct length! Combination: " << combo << endl;
    //        break;
    //    }
    //    if (p.checkForInvalidVowels(combo)) {
    //        cout << "\nERROR! Combination has too many vowels! Combination: " << combo << endl;
    //        break;
    //    }
    //    //int combocopies = std::count(p.combinations.begin(), p.combinations.end(), combo);
    //    if (combo == lastCombo)
    //        p2Copies.push_front(combo);// += combocopies - 1
    //    lastCombo = combo;
    //    //if ((std::find(p2.combinations.begin(), p2.combinations.end(), combo) == p2.combinations.end()))
    //    //    cout << combo << " ";*/
    //}
    for (string combo : p2.combinations) {
        if (combo.length() != 10) {
            cout << "\nERROR! Combination is not correct length! Combination: " << combo << endl;
            break;
        }
        if (p.checkForInvalidVowels(combo)) {
            cout << "\nERROR! Combination has too many vowels! Combination: " << combo << endl;
            break;
        }
        if (combo == lastCombo)
            p2Copies.push_front(combo);// += combocopies - 1
        lastCombo = combo;
    }
        
    //cout << "\n\nTotal Combinations in p: " << p.combinations.size();
    for (string copy : p2Copies)
        cout << copy << " ";
    cout << "\n\nTotal Combinations in p2: " << p2.combinations.size();
    cout << "\n\nCopies in p2: " << p2Copies.size();

}

