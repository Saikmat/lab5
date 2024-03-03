/*
 * Copyright 2024 - Howard Community College All rights reserved; Unauthorized duplication prohibited.
 * Name: Sai Matukumalli
 * Program name: Planets
 * Program description: This planet class defines objects to store information about a planet. It can store the planet
 * name, the planet number from the sun, and the number of moons it has. It includes getters for all perameters but
 * only a setter for the name, since the other information is updated using methods based on the name. It also includes
 * overrides for many of the common unary and binary operators to work with the object.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include "Planet.h"


using namespace std;

const string DEFAULT_PLANET_NAME = "None";
const string FIRST_PLANET = "Mercury";
const string LAST_PLANET = "Neptune";


/*
 * Given the name of the planet as set by the setName or the Planet Constructor, set the planet number
 * No return value since it is updating a private field
 */
void Planet::numberSetter(){
    if(name == "Mercury"){
        planetNumber = 1;
    } else if (name == "Venus"){
        planetNumber = 2;
    } else if (name == "Earth"){
        planetNumber = 3;
    } else if (name == "Mars"){
        planetNumber = 4;
    } else if (name == "Jupiter"){
        planetNumber = 5;
    } else if (name == "Saturn"){
        planetNumber = 6;
    } else if (name == "Uranus"){
        planetNumber = 7;
    } else if (name == "Neptune"){
        planetNumber = 8;
    } else {
        planetNumber = 0;
    }
}

/*
 * Sets the number of moons given the planet number
 * No return value since it sets private values with a private function
 */
void Planet::moonSetter(){
    /*
a. Mercury – 0
b. Venus – 0
c. Earth – 1
d. Mars – 2
e. Jupiter – 79
f. Saturn – 82
g. Uranus – 27
h. Neptune – 14
    */
    if(planetNumber == 1){
        numberOfMoons = 0;
    } else if (planetNumber == 2){
        numberOfMoons = 0;
    } else if (planetNumber == 3){
        numberOfMoons = 1;
    } else if (planetNumber == 4){
        numberOfMoons = 2;
    } else if (planetNumber == 5){
        numberOfMoons = 79;
    } else if (planetNumber == 6){
        numberOfMoons = 82;
    } else if (planetNumber == 7){
        numberOfMoons = 27;
    } else if (planetNumber == 8){
        numberOfMoons = 14;
    } else {
        numberOfMoons = 0;
    }
}

/*
 * Finds the name when given a planet number, so that entries can be updated
 * No return since it is a private function and updating private data values.
 */
void Planet::nameFromNumber(){
    switch(planetNumber){
        case 1: name = "Mercury"; break;
        case 2: name = "Venus"; break;
        case 3: name = "Earth"; break;
        case 4: name = "Mars"; break;
        case 5: name = "Jupiter"; break;
        case 6: name = "Saturn"; break;
        case 7: name = "Uranus"; break;
        case 8: name = "Neptune"; break;
        default: name = DEFAULT_PLANET_NAME; break;
    }
}

/*
 * Default constructor, taking no parameters and setting all values to their default
 */
Planet::Planet(){
    setName(DEFAULT_PLANET_NAME);
    this->numberSetter();
    this->moonSetter();
}

/*
 * Constructor that takes the name of the planet(title case sensitive) and updates the planet number and number of moons
 */
Planet::Planet(string pName){
    setName(pName);
    numberSetter();
    moonSetter();
}

/*
 * (string) Returns the name of the planet
 */
string Planet::getName() const{
    return name;
}

/*
 * (int) Returns the planet number
 */
int Planet::getPlanetNumber() const{
    return planetNumber;
}

/*
 * (int) Returns the number of moons that the planet has
 */
int Planet::getNumberOfMoons() const{
    return numberOfMoons;
}

/*
 * Sets the name of the planet
 * Should be called with other updating methods to fix the planet number and the number of moons
 */
void Planet::setName(string pName){
    this->name = pName;
}

/*
 * Overrides the plus operator to be unary, and returns a planet that is corresponding to Neptune
 */
Planet* Planet::operator+(){
    return new Planet(LAST_PLANET);
}

/*
 * Overrides the minus operator to be unary, and returns a planet that is corresponding to Mercury
 */
Planet* Planet::operator-(){
    return new Planet(FIRST_PLANET);
}

/*
 * Prefix operator to add one to the planet number and return the resultant planet's information
 */
Planet* Planet::operator++(){
    this->planetNumber++;
    if(planetNumber > 8){
        planetNumber = 1;
    }
    this->nameFromNumber();
    this->moonSetter();
    return this;
}

/*
 * Postfix operator to add one to the planet number and return the resulant planet's information
 */
Planet* Planet::operator++(int){
    this->planetNumber++;
    if(planetNumber > 8){
        planetNumber = 1;
    }
    this->nameFromNumber();
    this->moonSetter();
    return this;
}

/*
 * Sets planets to be equal to each other by values contained within
 */
Planet& Planet::operator=(Planet *p){
    this->name = p->name;
    this->planetNumber = p->planetNumber;
    this->numberOfMoons = p->numberOfMoons;
    return *this;
}

/*
 * Allows read into the function that takes the planet name and sets all data values within the object given the name
 */
std::istream &operator>>(std::istream &is, Planet &p) {
    string name;
    cout << "Enter the planet name: ";
    cin >> name;
    p.setName(name);
    p.numberSetter();
    p.moonSetter();
    return is;
}

/*
 * Prints the data values of the object when fed directly to cout
 */
ostream &operator<<(ostream &os, Planet &p){
    os << "The planet " << p.getName() << " is planet number " << p.getPlanetNumber() << endl;
    os << "It has " << p.getNumberOfMoons() << " moons.\n\n";
    return os;
}

/*
 * Prints HCC copyright statement
 */
void Planet::printCopyright() {
    cout << "\n\n\nCopyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited\n\n\n\n";
}



