/*
Program: Recycling Rewards Program
Process: This program calculates the total entertainment points based on the number of bottles, cans, and boxes collected. It then determines how many Cedar Point, Zoo, and MOvie tickets can be redeemed.
Results: The program produces the output the total entertainment points, the number of tickets for Cedar Ponts, zoo, and movie theatre, and any leftover points.
Class: CS2010
Term: Spring 2025
Name: Srijana Karki
Program: Karki_pgm2
Due: 2/8/2025
Reflection: This assignment helped me practice constants, integer division, and logical ordering of calculations. It reinforced the imporatnce of user-friendl input and output rompts and code readability.
*/
#include <iostream>
using namespace std;
int main() {
	// Constant values for recycling point
	const int pointsPerCan = 2;
	const int pointsPerBottle = 10;
	const int pointsPerBox = 20;
	
	//Constant values for ticket costs;
	const int cedarPointCost = 600;
	const int zooCost = 80;
	const int movieCost = 8;
	 
	// Variables to store user input
	int numCans, numBottles, numBoxes;
	// Input
	cout << "Enter the number of bottles = ";
	cin >> numBottles;
	cout << "Enter the number of cans =    ";
	cin >> numCans;
	cout << "Enter the number of boxes =   ";
	cin >> numBoxes;
	// Caculations
	// Calculating total enntertainment points
	int totalPoints = (numBottles * pointsPerBottle) + (numCans * pointsPerCan) + (numBoxes * pointsPerBox);
	// Calculating number of tickets
	int cedarTickets = totalPoints / cedarPointCost;
	totalPoints %= cedarPointCost; 
	int zooTicket = totalPoints / zooCost;
	totalPoints %= zooCost;
	int movieTickets = totalPoints / movieCost;
	totalPoints %= movieCost;

	// OUTPUTS
	cout << "--------------------" << endl;
	cout << "BG Recuclables" << endl;
	cout << "--------------------" << endl;
	cout << "Total entertainment points:  " << (numBottles * pointsPerBottle) + (numCans * pointsPerBottle) + (numBoxes * pointsPerBox) << endl;
	cout << "Total Cedar Point tickets:   " << cedarTickets << endl;
	cout << "Total Zoo tickets:           " << zooTicket << endl;
	cout << "Total Movie tickets:         " << movieTickets << endl;
	cout << "Leftover points:             " << totalPoints << endl;

	return 0;
}
