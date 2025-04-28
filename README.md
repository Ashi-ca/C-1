// -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -
// Program: The purpose of this program is about Softball Ticket Sales Profit Calculation
// Process: Input the number of tickets sold, calculate sales, expenses, and profits
// Results: Display the total ticket sales, expenses, and profits
// Class: CS2010
// Term: Spring 2025
// Time : 9:30 am
// Program Number : 1
// File Name : KarkiS_Pgm1
// Due Date : 1/26/2025 at 12:00 am
// Author: Srijana Karki
//Reflection: This program helps practice input, output, and basic calculations in C++.
//The main challenge was using constant and variables efficiently while ensuring correct formatting of the output.
//The program successfully computes the totalsales, expenses, and profits from the number of tickets sold and display them with appropriate precision 
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#include <iostream>
#include <iomanip> //For setting output format
using namespace std;
int main() {
	// constants
	const double Lower_deck_price = 17.50;
	const double Upper_deck_price = 7.10;
	const double Expenses_percentage = 0.30;
	const double Profits_percentage = 0.70;

	//Variables
	int lowerDeckTickets, upperDeckTickets;
	double totalSales, expenses, profits;
	 //Getting user input
	cout << "How many lower deck tickets were sold: ";
	cin >> lowerDeckTickets;
	cout << "How many upper deck tickets were sold: ";
	cin >> upperDeckTickets;

	// calculating total sales
	totalSales = (lowerDeckTickets * Lower_deck_price) + (upperDeckTickets * Upper_deck_price);
	expenses = totalSales * Expenses_percentage;
	profits = totalSales * Profits_percentage;
	//Displaying
	cout << "Ticket Sales: $" << totalSales << endl;
	cout << "Expenses: $" << expenses<< endl;
	cout << "Profits: $" << profits << endl;

	return 0;

}
