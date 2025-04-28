//-= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -= -
// Program: Realtor Competion Program
// Process: The program reads realtor and number of houses sold
// from file, converts negative values to positive, diplays 
// Results: The results displays the sales info for each realtor
// and alo indentifies the maximum and minimum sellers, adn total sales.
// Class: CS2010
// Term: Spring 2025
// Author: Srijana Karki
// Program:SrijanaK_pgm5
// Due: 04/06/2025
//Reflection: This program helped me understand how to read data 
// from afile into parallel arrays, process values using loops, 
// adn format meaningful output. I also got to practice finding
// max and min using arrays.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>  //this is for abs
using namespace std;
// For global constants
const int MAX_R = 25;
int main() {
	string realtor[MAX_R];
	int houses[MAX_R];
	//Variables to count the actual number of realtores in the file 
	int numRealtors = 0;
	//Create file stream to read input data
	ifstream infile;
	infile.open("pgm5.txt");
	//check if file opened successfully
	if (!infile) {
		cerr << "Error opening file" << endl;
		return 1; //Exits if file cannot be opened
	}
	//Sentinel loop to read file untilend-of-file or max size reached
	while (!infile.eof() && numRealtors < MAX_R) {
		infile >> realtor[numRealtors] >> houses[numRealtors]; //This reads name and houses sold
		//Converting negative house sales to positive using abs()
		houses[numRealtors] = abs(houses[numRealtors]);
		//Move to next index in array
		numRealtors++;
	}
	//Closing the file  after reading 
	infile.close();
	//This for loop displays all the realtors and number of houses sold 
	for (int i = 0; i < numRealtors; i++) {
		cout << "Realtor " << i + 1 << " who named " << realtor[i] << " sold " << houses[i] << endl;
	}
	//Initialize variables to track max/min and total
	int maxIndex = 0;
	int minIndex = 0;
	int total = 0;

	//This loop helps to find max,min and compute total by going through all realtors
	for (int i = 0; i < numRealtors; i++) {
		//checking for maximum houses sold;
		if (houses[i] > houses[maxIndex]) {
			maxIndex = i;
		}
		//for minimum houses sold
		if (houses[i] < houses[minIndex]) {
			minIndex = i;
		}
		//Adding current realtor's sale to total
		total += houses[i];

	}
	//Output of th realtor who sold  most houses
	cout << "The winner is Realtor " << maxIndex + 1 << " who named " << realtor[maxIndex] << " by selling " << houses[maxIndex] << " houses." << endl;

	//The one who sold least houses
	cout << "Realtor " << maxIndex + 1 << " who named " << houses[minIndex] << "." << endl;
	//Total Houses sold by all
	cout << "In total all Realtors sold " << total << " houses." << endl;
	return 0;
	
}
