#include <string>
#include "Dish.h"

using namespace std;

//constructors

//Default constructor
Dish::Dish() : dishName("Name"), dishPrice(0), dishType(0) {}

/*Constructor to create dish with given parameters
*  @Param dishName, string, name of dish.
*  @param dishPrice, unsigned int, price of dish
*  @param dishType, unsigned int, type of dish (0 = Appetizer, 1 = Entree, 2 = Dessert)
*/
Dish::Dish(const string& Name, unsigned int Price, unsigned int Type) : dishName(Name), dishPrice(Price), dishType(Type) {}

// getters
//Gets name of Dish object
string Dish::getName() const { return dishName; }

//Gets price of Dish object
unsigned int Dish::getPrice() const { return dishPrice;}

//Gets type of dish object
unsigned int Dish::getType() const { return dishType; }

//setters
//Sets name of Dish object
void Dish::setName(const string& newName) { dishName = newName; }

//Sets Price of Dish object
void Dish::setPrice(unsigned int newPrice) { dishPrice = newPrice; }

//Sets Type of Dish object
void Dish::setType(unsigned int newType) { dishType = newType; }


//Class member functions

/*  Prints out the Dish and price.
*	@Param: output file stream
*	Void return
*/
void Dish::printDish(ofstream& out) const {
	out << dishName << " ($" << dishPrice << ")" << endl;
}