// -------------------------------------------------------
//Program: Vending Machine Program.
//Process: This program simulates a vending machine
//			that allows the uswer to selcet a beverage,
//          enter the type(if applicable), make a payment,
//		    and receive change if necessary.
//Results: The program validates ther user's input, 
//		   calculates the total cost, accepts payments, 
//		   and returns change when applicable								
//Class: CS2010											
//Term: Spring 2025										
//Author: Srijana Karki			  
//Program: KarkiS_pgm3			  
//Due: 2/23/2025				      				  
// --------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
//CONSTANTS
const double waterPrice = 1.45;
const double lemonadePrice = 1.55;
const double colaPrice = 1.75;
const double rootBeerPrice = 1.15;
const double maxPayment = 10.00;
int main() {
	char choice = ' ';
	char type = ' '; // Varibales for storing user choice for drink selection, type for drink type.
	double price = 0.0, payment = 0.0, additionalPayment = 0.0; // for tracking

	// DISPLAY MENU
	cout << "--------------------------------------------" << endl;
	cout << "Welcome to the Vending Maching!" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "******************" << endl;
	cout << " Items Avaiable" << endl;
	cout << "******************" << endl;
	cout << "B - Bottled Water: $" << waterPrice << endl;
	cout << "L - Lemonade:      $" << lemonadePrice << endl;
	cout << "C - Cola:          $" << colaPrice << endl;
	cout << "R - Root Beer:     $" << waterPrice << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	choice = toupper(choice); // Converts the user input to uppercase for xas-insensitive handling
	switch (choice) {
	case 'B':
		price = waterPrice;
		break;
	case 'L': case 'C': case 'R':
		cout << "Enter type (L for Light, R for Regular): " << endl;
		cin >> type;
		type = toupper(type);
		if (type != 'L' && type != 'R') {
			cout << "Invalid Type. Exiting program.";
			return 0;
		}
		// Making it price based on user drink choice 
		if (choice == 'L') {
			price = lemonadePrice;
		}
		else if (choice == 'C') {
			price = colaPrice;

		}
		else {
			price = rootBeerPrice;
		}
		break;
	default: // This handles invalid drink selection
		cout << "Invalid";
		return 0;
	}
	//Prompt user for payment
	cout << "Enter payment amount: " ;
	cin >> payment;
	if (payment < price) {
		cout << "Insufficient payment. Enter additional amount: " << endl;
		cin >> additionalPayment;
		payment += additionalPayment;
	}
	 //if (payment < price) {
		//cout << "Payment still insufficient. Returning Money. Exiting program.";
		//return 0;
	//}
	if (payment > maxPayment) {
		cout << "Payment exceeds maximum limit. Exiting" << endl;
		return 0;
	}
	// Calculating change to return.
	double change = payment - price; // Calculating the remaining balance
	cout << "Dispensing your item..."<< endl;
	cout << fixed << setprecision(2); //  ensuring currency format with two decimal places.
	cout << "Your change is: $" << change << endl;
	cout << "Thank You for usinng the vending machine:)" << endl;
	return 0; // End of the rpogram
}

