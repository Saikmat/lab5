/*
 * Copyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited.
 * Name: Sai Matukumalli
 * Program name: Planets Driver
 * Date: 10/12/2023
 * Program description: This driver is designed to test the planets class. It uses all methods in the class either
 * via calls within the function or by explicitly calling them.
 */

#include <iostream>
#include "main.h"
#include "planet.h"

using namespace std;

int main(){
    // 1
    Planet::printCopyright();
    //2
    Planet* planet1 = new Planet("Jupiter");
    //3
    Planet* planet2 = new Planet();
    Planet* planet3 = new Planet();
    Planet* planet4 = new Planet();
    Planet* planet5 = new Planet();
    Planet* planet6 = new Planet();
    //4
    cout << "Non-overloaded print call" << endl;
    cout << "The name of the planet is: " << planet1->getName() <<
         "\nIt is planet number: " << planet1->getPlanetNumber() <<
         "\nIt has " << planet1->getNumberOfMoons() << " Moons.\n\n";
    //5
    cout << "Using overloaded output stream operator" << endl;
    cout << *planet1;
    //6a
    cout << "Using overloaded Prefix increment operator on planet 2" << endl;
    *planet2 = ++*planet1;
    //6b
    cout << *planet2;
    //7a
    cout << "Using overloaded Postfix increment operator on Planet 3" << endl;
    *planet3 = (*planet1)++;
    //7b
    cout << *planet3;
    //8a
    cout << "Using overloaded stream Input operator on Planet 4" << endl;
    cin >> *planet4;
    //8b
    cout << *planet4;
    //9a
    cout << "Using overloaded Minus operator on Planet 5" << endl;
    *planet5 = -*planet5;
    //9b
    cout << *planet5;
    //10a
    cout << "Using overloaded Plus operator on Planet 6" << endl;
    *planet6 = +*planet6;
    //10b
    cout << *planet6;
    //11
    cout << "Thank you for using the planets class" << endl;
    
    return 0;
}