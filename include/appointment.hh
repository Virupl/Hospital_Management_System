#ifndef APPOINTMENT
#define APPOINTMENT

#include <string>
#include <vector>
using namespace std;

class appointment
{
protected:
    int id = 1, hh = 9;
    string Pname, Dname;
    string Pid, Did;
    string PFirst, PSecond, PThird, Pline;
    string DFirst, DSecond, DThird, Dline;
    vector<string> Plines;
    vector<string> Dlines;

public:
    void book();
    void getappointment();
    void showallAp();
    void printDetails();
    void fillData();
};

#endif