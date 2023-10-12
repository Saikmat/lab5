#include <iostream>
#include <string>



class Planet{

private:
    std::string name;
    int planetNumber;
    int numberOfMoons;
    
    void numberSetter(std::string name);
    
    void moonSetter(std::string name);

public:
    
    Planet();
    
    Planet(std::string);
    
    inline std::string getName(){return name;};
    
    inline int getPlanetNumber(){return planetNumber;};
    
    inline int getNumberOfMoons(){return numberOfMoons;};
    
    inline void setName(std::string name){this->name = name;};
    
    void setPlanetNumber();
    
    void setNumberOfMoons();
    
    Planet operator+();
    
    Planet operator-();
    
    Planet operator++();
    
    Planet operator++(int);
    
    Planet operator=(Planet);
    
    friend std::istream& operator>>(std::istream, Planet);
    
    friend std::ostream& operator<<(std::ostream, Planet);
    
    
};