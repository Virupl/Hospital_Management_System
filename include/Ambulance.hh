#ifndef AMBULANCES
#define AMBULANCES

using namespace std;
#include <string>

class Ambulance
{
private:
    int ID = 4001;
    string Model, Manufacturer, Vrn;

public:
    // Ambulance();
    string lastlineReadCSV();
    void input();
};

#endif