#include <tuple>
#include "PuzzleSolver.h"

PuzzleSolver::PuzzleSolver() {}

void PuzzleSolver::findCombinationsFromPos(string combination, array<int, 2> currentPos) {
    cout << "\ncombination so far: " << combination;
    // Clear the combination if it contains the error-character "*" or if it contains >2 vowels
    if (combination[combination.length() - 1] == *"*" || checkForInvalidVowels(combination)) {
        cout << " - Bad combo";
    }
    else if (combination.length() >= 10) {
        combinations.push_back(combination);
    }
    else {
        array<int, 2> newPos;
        char newChar;
        // Recursively call self 8 times, one for each possible move
        newPos = moveNNE(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        newPos = moveNEE(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        newPos = moveSEE(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        newPos = moveSSE(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        newPos = moveSSW(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        newPos = moveSWW(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        newPos = moveNWW(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        newPos = moveNNW(currentPos);
        newChar = getLetterAtPos(newPos);
        findCombinationsFromPos(combination + newChar, newPos);
        //findCombination(combination + moveSEE(currentPos), currentX + 2, currentY + 1);
        //findCombination(combination + moveSSE(currentPos), currentX + 1, currentY + 2);
        //findCombination(combination + moveSSW(currentPos), currentX - 1, currentY + 2);
        //findCombination(combination + moveSWW(currentPos), currentX - 2, currentY + 1);
        //findCombination(combination + moveNWW(currentPos), currentX - 2, currentY - 1);
        //findCombination(combination + moveNNW(currentPos), currentX - 1, currentY - 2);
        //findCombination(combination + moveNNE(currentPos), currentX + 1, currentY - 2);
        //findCombination(combination + moveNEE(currentPos), currentX + 2, currentY - 1);
    }
}


char PuzzleSolver::getLetterAtPos(array<int, 2> pos) {
    int col = pos[0];
    int row = pos[1];
    if (col < 0 || col >= keyboard[0].size() || row < 0 || row >= keyboard.size())
        return '*';
    else {
        return keyboard[row][col];
    }
}

bool PuzzleSolver::checkForInvalidVowels(string combination) {
    //Test if there are more than 2 vowels in a combination
    int count = 0;
    for (char c : combination) {
        if (vowels.find(c) != vowels.end())
            count++;
        if (count > 2)
            return true;
    }
    return false;
}

array<int, 2> PuzzleSolver::moveSEE(array<int, 2> pos) {
    //Move South, East, East, then find all new combinations stemming from that position
    int newX = pos[0] + 2;
    int newY = pos[1] + 1;
    return array<int, 2>{newX, newY};
}

array<int, 2> PuzzleSolver::moveSSE(array<int, 2> pos) {
    //Move South, South, East
    int newX = pos[0] + 1;
    int newY = pos[1] + 2;
    return array<int, 2>{newX, newY};
}
array<int, 2> PuzzleSolver::moveSSW(array<int, 2> pos) {
    //Move South, South, West
    int newX = pos[0] - 1;
    int newY = pos[1] + 2;
    return array<int, 2>{newX, newY};
}

array<int, 2> PuzzleSolver::moveSWW(array<int, 2> pos) {
    //Move South, West, West
    int newX = pos[0] - 2;
    int newY = pos[1] + 1;
    return array<int, 2>{newX, newY};
}

array<int, 2> PuzzleSolver::moveNWW(array<int, 2> pos) {
    //Move North, West, West
    int newX = pos[0] - 2;
    int newY = pos[1] - 1;
    return array<int, 2>{newX, newY};
}

array<int, 2> PuzzleSolver::moveNNW(array<int, 2> pos) {
    //Move North, North, West
    int newX = pos[0] - 1;
    int newY = pos[1] - 2;
    return array<int, 2>{newX, newY};
}

array<int, 2> PuzzleSolver::moveNNE(array<int, 2> pos) {
    //Move North, North, East
    int newX = pos[0] + 1;
    int newY = pos[1] - 2;
    return array<int, 2>{newX, newY};
}

array<int, 2> PuzzleSolver::moveNEE(array<int, 2> pos) {
    //Move North, East, East
    int newX = pos[0] - 2;
    int newY = pos[1] - 1;
    return array<int, 2>{newX, newY};
}