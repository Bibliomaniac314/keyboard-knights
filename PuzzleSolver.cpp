#include <tuple>
#include "PuzzleSolver.h"

PuzzleSolver::PuzzleSolver(int length) {
	combinationLength = length;
}

void PuzzleSolver::findCombinationsFromPos(string combination, array<int, 2> currentPos) {
	cout << "\ncombination so far: " << combination;
	// Clear the combination if it contains the error-character "*" or if it contains >2 vowels
	if (combination[combination.length() - 1] == *"*" || checkForInvalidVowels(combination)) {
		cout << " - Bad combo";
		return;
	}
	// Save combination and return if combination is correct length
	else if (combination.length() >= combinationLength) {
		combinations.push_back(combination);
		return;
	}
	else {
		// Else recursively call self up to 8 times, once for each possible move
		array<int, 2> newPos;
		char newChar;
		newPos = moveNNE(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
		newPos = moveNEE(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
		newPos = moveSEE(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
		newPos = moveSSE(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
		newPos = moveSSW(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
		newPos = moveSWW(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
		newPos = moveNWW(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
		newPos = moveNNW(currentPos);
		if (newPos[0] >= 0 && newPos[1] >= 0) {
			newChar = getLetterAtPos(newPos);
			findCombinationsFromPos(combination + newChar, newPos);
		}
	}
}


char PuzzleSolver::getLetterAtPos(array<int, 2> pos) {
	// Get the letter found at a given position (specified by [row, col])
	int row = pos[0];
	int col = pos[1];
	if (col < 0 || col >= keyboard[0].size() || row < 0 || row >= keyboard.size())
		// If specified position is out of range of the table, return '*' to signify Invalid.
		return '*';
	else {
		return keyboard[row][col];
	}
}

bool PuzzleSolver::checkForInvalidVowels(string combination) {
	// Test if there are more than 2 vowels in a combination
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
	// Move South, East, East, then find all new combinations stemming from that position
	int newRow = pos[0] + 1;
	int newCol = pos[1] + 2;
	return array<int, 2>{newRow, newCol};
}

array<int, 2> PuzzleSolver::moveSSE(array<int, 2> pos) {
	// Move South, South, East
	int newRow = pos[0] + 2;
	int newCol = pos[1] + 1;
	return array<int, 2>{newRow, newCol};
}
array<int, 2> PuzzleSolver::moveSSW(array<int, 2> pos) {
	// Move South, South, West
	int newRow = pos[0] + 2;
	int newCol = pos[1] - 1;
	return array<int, 2>{newRow, newCol};
}

array<int, 2> PuzzleSolver::moveSWW(array<int, 2> pos) {
	// Move South, West, West
	int newRow = pos[0] + 1;
	int newCol = pos[1] - 2;
	return array<int, 2>{newRow, newCol};
}

array<int, 2> PuzzleSolver::moveNWW(array<int, 2> pos) {
	// Move North, West, West
	int newRow = pos[0] - 1;
	int newCol = pos[1] - 2;
	return array<int, 2>{newRow, newCol};
}

array<int, 2> PuzzleSolver::moveNNW(array<int, 2> pos) {
	// Move North, North, West
	int newRow = pos[0] - 2;
	int newCol = pos[1] - 1;
	return array<int, 2>{newRow, newCol};
}

array<int, 2> PuzzleSolver::moveNNE(array<int, 2> pos) {
	// Move North, North, East
	int newRow = pos[0] - 2;
	int newCol = pos[1] + 1;
	return array<int, 2>{newRow, newCol};
}

array<int, 2> PuzzleSolver::moveNEE(array<int, 2> pos) {
	// Move North, East, East
	int newRow = pos[0] - 1;
	int newCol = pos[1] + 2;
	return array<int, 2>{newRow, newCol};
}