#ifndef OTHERSTAFF
#define OTHERSTAFF

using namespace std;
#include <string>

class othStaff_Class
{
private:
    int ID = 5001;
    int minAge = 18, maxAge = 50;
    int Age;
    char Gender;
    string FirstName, LastName, Mobile_no, Address, JoinDate, Department;

public:
    string lastlineReadCSV();
    void input();
};

#endif