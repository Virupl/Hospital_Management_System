#ifndef DRIVERS
#define DRIVERS

using namespace std;
class Drivers
{
private:
    int minAge = 18, maxAge = 65;
    int ID = 3001;
    int Age;
    char Gender;
    string FirstName, LastName, Mobile_no, Address, JoinDate;

public:
    string lastlineReadCSV();
    void input();
};

#endif