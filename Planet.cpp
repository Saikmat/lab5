#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

const string DEFAULT_PLANET_NAME = "None";
const string FIRST_PLANET = "Mercury";
const string LAST_PLANET = "Neptune";
/* Gaddis, Tony. Starting Out with C++: From Control Structures through Objects. 9th ed., Pearson Education (US), 2017. p. 1054.
 * Checking the string against each value and then assigning the number of moons is possible in 3 ways
 * 1. if-else if-else statements
 * 2. Hash the string and pass to a switch
 * 3. Find the value in a map
 * The if statement method requires 8n, where n is the length of the string, comparisons.
 * The switch can be converted into a jump table but hashing the string still requires 9n computations, plus the integer comparisons, .
 * Using a map hashes the string values during compile time, so the 8n of hashing during compile can be ignored.
 * This means that during run time, there are only n(length of name) + 1 for access computations required, making it the fastest option.
 */
const unordered_map<string, int> moons = {
        {"Mercury", 0},
        {"Venus",   0},
        {"Earth",   1},
        {"Mars", 3},
        {"Jupiter", 79},
        {"Saturn", 82},
        {"Uranus", 27},
        {"Neptune", 14}
};

class Planet{

private:
    string name;
    int planetNumber;
    int numberOfMoons;
    
    void numberSetter(){
        planetNumber = distance(moons.begin(), moons.find(name));
    }
    
    void moonSetter(){
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
//        if(name == "Mercury"){
//            numberOfMoons = 0;
//        } else if (name == "Venus"){
//            numberOfMoons = 0;
//        } else if (name == "Earth"){
//            numberOfMoons = 1;
//        } else if (name == "Mars"){
//            numberOfMoons = 2;
//        } else if (name == "Jupiter"){
//            numberOfMoons = 79;
//        } else if (name == "Saturn"){
//            numberOfMoons = 82;
//        } else if (name == "Uranus"){
//            numberOfMoons = 27;
//        } else if (name == "Neptune"){
//            numberOfMoons = 14;
//        }

numberOfMoons = moons.find(name)->second;
    }
    
    string nameFromNumber(int val){
    
    }

public:
    
    Planet(){
        setName(DEFAULT_PLANET_NAME);
        this->numberSetter();
        this->moonSetter();
    }
    
    Planet(string pName){
        setName(pName);
        numberSetter();
        moonSetter();
    }
    
    string getName(){
        return name;
    }
    
    int getPlanetNumber(){
        return planetNumber;
    }
    
    int getNumberOfMoons(){
        return numberOfMoons;
    }
    
    void setName(string pName){
        this->name = pName;
    } //might need to be private
    
    Planet* operator+(){
        return new Planet(LAST_PLANET);
    }
    
    Planet* operator-(){
        return new Planet(FIRST_PLANET);
    }
    
    Planet* operator++(){
        this->planetNumber++;
        this->setName(nameFromNumber(planetNumber));
        this->moonSetter();
        return this;
    }
    
    Planet* operator++(int){
        this->planetNumber++;
        this->setName(nameFromNumber(planetNumber));
        this->moonSetter();
        return this;
    }
    
    Planet operator=(Planet p){
        p.name = this->name;
        p.planetNumber = this->planetNumber;
        p.numberOfMoons = this->numberOfMoons;
        return p;
    }
    
    friend istream& operator>>(istream &is, Planet &p){
        string name;
        cout << "Enter the planet name";
        is >> name;
        p.setName(name);
        p.moonSetter();
        p.numberSetter();
        return is;
    }
    
    friend ostream& operator<<(ostream &os, Planet &p){
        os << "The planet's name is " << p.getName() << endl;
        os << "It has " << p.getNumberOfMoons() << "moons";
        return os;
    }
};