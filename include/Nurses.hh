#ifndef NURSES
#define NURSES

using namespace std;

class Nurses
{
private:
    int ID = 2001;
    int minAge = 18, maxAge = 50;
    int Age;
    char Gender = 'F';
    string FirstName, LastName, Mobile_no, Address, JoinDate;

public:
    string lastlineReadCSV();
    void input();
};

#endif