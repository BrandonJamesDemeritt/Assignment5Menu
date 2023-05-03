#ifndef DISH_H
#define DISH_H
#include <string>
#include <fstream>

using namespace std;

class Dish {

public:

	//constructors
	//Default Contuctor declaration
 	Dish();
	//Overloaded constructor declaration
	Dish(const string&, unsigned int, unsigned int);

	//getters
	string getName() const;
	unsigned int getPrice() const;
	unsigned int getType() const;
	
	//setters
	void setName(const string&);
	void setPrice(unsigned int);
	void setType(unsigned int);

	//class member methods
	void printDish(ofstream&) const;

private:

	//data fields
	string dishName;
	unsigned int dishType;
	unsigned int dishPrice;
};
#endif
