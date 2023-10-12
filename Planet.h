#include <iostream>
#include <string>



class Planet{

private:
    std::string name;
    int planetNumber;
    int numberOfMoons;

    void numberSetter();

    void moonSetter();

    void nameFromNumber();

public:

    Planet();

    Planet(std::string);

    std::string getName() const;

    int getPlanetNumber() const;

    int getNumberOfMoons() const;

    void setName(std::string name);

    Planet* operator+();

    Planet* operator-();

    Planet* operator++();

    Planet* operator++(int);

    Planet& operator=(Planet*);

    friend std::istream& operator>>(std::istream&, Planet&);

    friend std::ostream& operator<<(std::ostream&, Planet&);

    static void printCopyright();


};