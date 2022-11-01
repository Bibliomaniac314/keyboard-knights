// PuzzleSolver.h : This file contains the declaration of all variables and methods used in solving the Keyboard Knights puzzle.
//
#pragma once
#include <list>
#include <set>
#include <iostream>
#include <array>
using namespace std;

const array<array<char, 5>, 4> keyboard = { {
                                {'A', 'B', 'C', 'D', 'E'},
                                {'F', 'G', 'H', 'I', 'J'},
                                {'K', 'L', 'M', 'N', 'O'},
                                {'*', '1', '2', '3', '*'} } };
const set<char> vowels = { 'A', 'E', 'I', 'O' };

class PuzzleSolver
{
public:
    PuzzleSolver();
    list<string> combinations = list<string>{};
    void findCombinationsFromPos(string combination, array<int, 2> currentPos);
    static char getLetterAtPos(array<int, 2> pos);
    static array<int, 2> moveSEE(array<int, 2> pos);
    static array<int, 2> moveSSE(array<int, 2> pos);
    static array<int, 2> moveSSW(array<int, 2> pos);
    static array<int, 2> moveSWW(array<int, 2> pos);
    static array<int, 2> moveNWW(array<int, 2> pos);
    static array<int, 2> moveNNW(array<int, 2> pos);
    static array<int, 2> moveNNE(array<int, 2> pos);
    static array<int, 2> moveNEE(array<int, 2> pos);
    static bool checkForInvalidVowels(string combination);
};

