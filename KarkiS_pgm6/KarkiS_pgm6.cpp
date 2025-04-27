//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Reads products data, processes and analyzes it
// Process: Reads from file into arrays, sorts data, finds max price, averages, etc.
// Results: Prints product list, understock items, highest price item, and warehouse averages
// Class: CS2010
// Term: Spring 2025
// Author: Srijana Karki
// Program: Karki_pgm6
// Due: 04/27/2025
//
// Reflection: This assignment helped me reinforce reading from files, 
// using arrays, and processing structured data using functions.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//Constant for array size
const int MAX_PRODUCTS = 30;
//Function Prototypes
void ReadData( string item[], int qty[], string location[], double price[],int& numProducts);
void SelSort(string item[], int qty[], string location[], double price[], int numProducts);
void PrintArrays(const string item[], const int qty[], const  string location[], const double price[], int numProducts);
void Restock(const string item[], const int qty[],int numProducts);
int HiPrice( const double price[], int numProducts);
void AverWarehouse(const string location[], const double price[], int numProducts, double& avgC, double& avgJ, double& avgM);
int main() {
	string item[MAX_PRODUCTS];
	int qty[MAX_PRODUCTS];
	string location[MAX_PRODUCTS];
	double price[MAX_PRODUCTS];
	int numProducts = 0; //Number of products read from file
	//Reading the data from file
	ReadData(item, qty, location, price, numProducts);
	//Sorting data(stub)
	SelSort(item, qty, location, price, numProducts);
	//Printing all arrays
	PrintArrays(item, qty, location, price, numProducts);
	Restock(item, qty, numProducts);
	//Get index of highest priced item
	int hiIndex = HiPrice(price, numProducts);
	cout << fixed << setprecision(2);
	cout << "The highest priced item is " << item[hiIndex]
		<< ", located in " << location[hiIndex]
		<< " with a price of $" << price[hiIndex] << endl;
	//Getting avg prices per warehouse
	double avgC, avgJ, avgM;
	AverWarehouse(location, price, numProducts, avgC, avgJ, avgM);
	cout << "Warehouse C average: $" << avgC << endl;
	cout << "Warehoue J average: $" << avgJ << endl;
	cout << "Warehouse M average: $" << avgM << endl;
	return 0;
}
//-------------------------------------------------------
// Function: ReadData
// Purpose: Reads product information from a file into arrays
// Argument: item, qty, location, price arrays, and numProducts by reference.
//-------------------------------------------------------
void ReadData(string item[], int qty[], string location[], double price[], int& numProducts) {
	ifstream inFile("products.txt");
	if (!inFile) {
		cout << "Error opening file.";
		return;
	}
	numProducts = 0;
	while (numProducts < MAX_PRODUCTS && getline(inFile, item[numProducts])) {
		string lineQty, lineLocation, linePrice;
		getline(inFile, lineQty);
		qty[numProducts] = stoi(lineQty);
		getline(inFile, location[numProducts]);
		getline(inFile, linePrice);
		price[numProducts] = stod(linePrice);
		numProducts++;
	}
	inFile.close();
}
//-------------------------------------------------------
// Function: SelSort
// Purpose: Sort arrays by item name using Selection Sort algorithm.
// Argument: item, qty, location, price arrays, and numProducts.
//-------------------------------------------------------
void SelSort(string item[], int qty[], string location[], double price[], int numProducts) {
	for (int i = 0; i < numProducts - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < numProducts; j++) {
			if (item[j] < item[minIndex]) {
				minIndex = j;
			}
		}
		swap(item[i], item[minIndex]);
		swap(qty[i], qty[minIndex]);
		swap(location[i], location[minIndex]);
		swap(price[i], price[minIndex]);
	}
}
//-------------------------------------------------------
// Function: PrintArrays
// Purpose: Prints the product data in a formatted table.
// Argument: item, qty, location, price arrays, and numProducts.
//-------------------------------------------------------
void PrintArrays(const string item[], const int qty[], const  string location[], const double price[], int numProducts) {
	cout << left << setw(20) << "Item" << setw(10) << "Qty" << setw(15) << "Location" << setw(10) << "Price" << endl;
	cout << "-------------------------------------------------------------" << endl;
	for (int i = 0; i < numProducts; ++i) {
		cout << left << setw(20) << item[i] << setw(10) << qty[i] << setw(15) << location[i] << "$" << fixed << setprecision(2) << price[i] << endl;
	}
}
//-------------------------------------------------------------
// Function: Restock
// Purpose: Prints the product data in a formatted table
// Argument: item, qty, location, price arrays, and numProducts.
//--------------------------------------------------------------
void Restock(const string item[], const int qty[], int numProducts) {
	cout << "Products understocked(< 100): " << endl;
	cout << left << setw(20) << "Item" << setw(10) << "Qty" << endl;
	cout << "-------------------------------------------------------------" << endl;
	for (int i = 0; i < numProducts; i++) {
		if (qty[i] < 100) {
			cout << left << setw(20) << item[i] << setw(10) << qty[i] << endl;
		}
	}
}
//-------------------------------------------------------
// Function: HiPrice
// Purpose: Finds the index of highest priced product
// Argument: price arrays, and numProducts by reference.
//-------------------------------------------------------
int HiPrice(const double price[], int numProducts){
	int maxIndex = 0;
	for (int i = 1; i < numProducts; ++i) {
		if (price[i] > price[maxIndex]) {
			maxIndex = i;
		}
	}
	return maxIndex;
}
//-------------------------------------------------------
// Function: AverWarehouse
// Purpose: Calculates avg
// Argument: location, price arrays, and numProducts, avgC, avgJ, avgM.
//-------------------------------------------------------
void AverWarehouse(const string location[], const double price[], int numProducts, double& avgC, double& avgJ, double& avgM) {
	double sumC = 0, sumJ = 0, sumM = 0;
	int countC = 0, countJ = 0, countM = 0;
	for (int i = 0; i < numProducts; ++i) {
		if (location[i] == "Warehouse C") {
			sumC += price[i];
			countC++;
		}
		else if (location[i] == "Warehouse J") {
			sumJ += price[i];
			countJ++;
		}
		else if (location[i] == "Warehouse M") {
			sumM += price[i];
			countM++;
		}
	}
	avgC = (countC > 0) ? sumC / countC : 0;
	avgJ = (countJ > 0) ? sumJ / countJ : 0;
	avgM = (countM > 0) ? sumM / countM : 0;

}
	



