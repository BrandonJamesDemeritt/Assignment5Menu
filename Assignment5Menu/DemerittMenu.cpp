#include "Dish.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Declaration of Trim() function
string trim(const string&);

int main() {

	//Variables
	string type;
	string name;
	unsigned int price;
	vector<Dish> Appetizers;
	vector<Dish> Entrees;
	vector<Dish> Desserts;
	unsigned int numType;
	string Temp;

	//open input file
	ifstream fin("dishes.txt");

	//test input file and output error if not found.
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//Create output file
	ofstream fout("Menu.txt");

	//Read in from file
	while (fin >> type, fin >> price, getline(fin, name)) {
		
		//Set type name to lowercase
		for (int i = 0; i < type.size(); ++i) {
			type.at(i) = tolower(type.at(i));
		}
		//Check if Appetizer type, if so, create appetizer dish with info
		if (type == "appetizer") {
			numType = 0;
			Appetizers.push_back(Dish::Dish(name, price, numType));
		}
		//Check if Entree type, if so, create entree dish with info
		if (type == "entree") {
			numType = 1;
			Entrees.push_back(Dish::Dish(name, price, numType));
		}
		//Check if dessert type, if so, create dessert dish with info
		if (type == "dessert") {
			numType = 2;
			Desserts.push_back(Dish::Dish(name, price, numType));
		}
	}

	//Remove leading and trailing spaces from all Appetizer names using Trim() and reassign to name of Appetizer
	for (int i = 0; i < Appetizers.size(); i++) {
		Temp = trim(Appetizers.at(i).getName());
		Appetizers.at(i).setName(Temp);
	}

	//Remove leading and trailing spaces from all Entree names using Trim() and reassign to name of Entree
	for (int i = 0; i < Entrees.size(); i++) {
		Temp = trim(Entrees.at(i).getName());
		Entrees.at(i).setName(Temp);
	}

	//Remove leading and trailing spaces from all Dessert names using Trim() and reassign to name of Dessert
	for (int i = 0; i < Desserts.size(); i++) {
		Temp = trim(Desserts.at(i).getName());
		Desserts.at(i).setName(Temp);
	}

	//Create output file Menu Header
	fout << "Menu" << endl << endl;

	//Create output file Appetizer Header
	fout << "Appetizers" << endl << endl;

	//Loop through eat Dish in Appertizers and Call PrintDish function for that appetizer
	for (int j = 0; j < Appetizers.size(); j++) {
		Appetizers.at(j).printDish(fout);
	}
	
	//Create output file Entree Header
	fout << endl << "Entrees" << endl << endl;
	
	//Loop through eat Dish in Entrees and Call PrintDish function for that entree
	for (int j = 0; j < Entrees.size(); j++) {
		Entrees.at(j).printDish(fout);
	}

	//Create output file Desserts Header
	fout << endl << "Desserts" << endl << endl;
	
	//Loop through eat Dish in Desserts and Call PrintDish function for that dessert
	for (int j = 0; j < Desserts.size(); j++) {
		Desserts.at(j).printDish(fout);
	}

	//Close files and exit
	fin.close();
	fout.close();
	return 0;
}

/*
* Trim(), returns a substring of the given string not including leading or trailing whitespace
* @Param, string, string to remove leading or trailing white spaces
* @Return substring
*/
string trim(const string& dName) {
	int s = 0;
	int e = dName.size() - 1;
	while (s < dName.size() && (dName[s] == ' ' || dName[s] == '\t')) { s++; }
	while (e >= 0 && (dName[e] == ' ' || dName[e] == '\t')) { e--; }
	return dName.substr(s, e - s + 1);
}