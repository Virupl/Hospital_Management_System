#ifndef ADDRESS
#define ADDRESS

using namespace std;
#include <string>

class Address_class
{
private:
    string line1, line2;
    string city;
    string state;
    string pinCode;
    string country;

public:
    Address_class();
    void takeInput();
    void print();
    string addToStr();
    void strToAdd(string);
};

#endif