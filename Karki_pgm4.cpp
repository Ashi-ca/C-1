//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Rock Paper Scissors Game
// Process: The program uses a Rock, Paper, Scissors game for two players
// It takes player names and rounds as input, generates random moves, determines roundwinners, and displays, the final results.
// Results: Displays the game results, including each rounds's winner and the final score.
//
// Class: CS2010
// Term: Spring 2025
// Author: Srijana Karki
// Program: Kakri_pgm4
// Due: 03/23/2025
//
// Reflection: This program helped me practice the use of loops, random number generation, and input validatio. Testing different scenarios improved debugging skills.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	srand(time(NULL)); // Random number generator
	string firstPlayer, secondPlayer;
	int rounds; //Number of rounds to be played
	char anotherRound; // Variables to store user's choice to play again
	do {
		// Reading player names
		cout << "Enter player's name = ";
		cin >> firstPlayer;
		cout << "Enter second player's name = ";
		cin >> secondPlayer;
		//for reading number of rounds with validation
		do {
			cout << "Enter the number of round(s): ";
			cin >> rounds;
			if (rounds < 1) {
				cout << "Rounds must be > 0" << endl;
			}
		} while (rounds < 1);
		cout << firstPlayer <<" vs " << secondPlayer << " for " << rounds << " round(s)"<< endl;
		cout << string(40, '-') << endl;
		int firstScore = 0, secondScore = 0;
		for (int i = 0; i < rounds; i++) {
			int firstMove, secondMove;
			do {
				firstMove = rand() % 3;
				secondMove = rand() % 3;
				if (firstMove == secondMove) {
					cout << "Tie" << endl;
				}
			} while (firstMove == secondMove);
			if ((firstMove == ROCK && secondMove == SCISSORS) ||
				(firstMove == SCISSORS && secondMove == PAPER) ||
				(firstMove == PAPER && secondMove == ROCK)) {
				cout << firstPlayer << " wins with " << (firstMove == ROCK ? "rock" : firstMove == PAPER ? "paper" : "scissors") << endl;
				firstScore++; // Increment first player's score
			}
			else {
				cout << secondPlayer << " wins with " << (secondMove == ROCK ? "rock" : secondMove == PAPER ? "paper" : "scissors") << endl;
				secondScore++; //Increment second player's score
			}


		}
		cout << string(40, '-') << endl;
		cout << firstPlayer << " wins " << firstScore << " and "<< secondPlayer << " win "<< secondScore << endl;

		do {
			cout << "Would you like to play another game ? If YES click 1,if NO click 2): ";
			cin >> anotherRound;
			if (anotherRound != '1' && anotherRound != '2') {
				cout << "Invalid input. Enter 1 for YES or 2 for no" << endl;
			}


		} while (anotherRound != '1' && anotherRound != '2');

	} while (anotherRound == '1');
	return 0;
}

