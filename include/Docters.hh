#ifndef DOCTERS
#define DOCTERS

using namespace std;

// Doctor
class Doctor
{
private:
    int ID = 1001;
    int age;
    int minAge = 18, maxAge = 65;
    char gender;
    string FirstName, LastName, Mobile_no, Address, JoinDate;

public:
    void Login_Doctor();
    void input();
    string lastlineReadCSV();
    void printDetails();
    void removeDocter();
};

#endif