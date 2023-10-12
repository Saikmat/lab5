#include <iostream>
#include <string>
#include <unordered_map>
#include "Planet.h"


using namespace std;

const string DEFAULT_PLANET_NAME = "None";
const string FIRST_PLANET = "Mercury";
const string LAST_PLANET = "Neptune";



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


Planet::Planet(){
    setName(DEFAULT_PLANET_NAME);
    this->numberSetter();
    this->moonSetter();
}

Planet::Planet(string pName){
    setName(pName);
    numberSetter();
    moonSetter();
}

string Planet::getName() const{
    return name;
}

int Planet::getPlanetNumber() const{
    return planetNumber;
}

int Planet::getNumberOfMoons() const{
    return numberOfMoons;
}

void Planet::setName(string pName){
    this->name = pName;
}


Planet* Planet::operator+(){
    return new Planet(LAST_PLANET);
}

Planet* Planet::operator-(){
    return new Planet(FIRST_PLANET);
}

/*
 * Prefix operator to add one to the planet and return the planet
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
 * Postfix operator to add one to the planet and return the planet
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

Planet& Planet::operator=(Planet *p){
    this->name = p->name;
    this->planetNumber = p->planetNumber;
    this->numberOfMoons = p->numberOfMoons;
    return *this;
}


std::istream &operator>>(std::istream &is, Planet &p) {
    string name;
    cout << "Enter the planet name: ";
    cin >> name;
    p.setName(name);
    p.numberSetter();
    p.moonSetter();
    return is;
}

ostream &operator<<(ostream &os, Planet &p){
    os << "The planet's name is " << p.getName() << endl;
    os << "It has " << p.getNumberOfMoons() << " moons\n\n";
    return os;
}

void Planet::printCopyright() {
    cout << "\n\n\nCopyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited\n\n\n\n";
}



