#ifndef PATIENT
#define PATIENT

using namespace std;
// Patient
class patient
{
private:
    int ID = 1201;
    int age;
    char Gender;
    string FirstName, LastName, Mobile_no, Address, BG, Date;

public:
    string lastlineReadCSV();
    void input();
};

#endif