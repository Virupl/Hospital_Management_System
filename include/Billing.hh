#ifndef BILLING
#define BILLING

using namespace std;

class Billing
{
private:
    struct bill
    {
        string pID;
        string pfname;
        string plname;
        string payment;
    };

public:
    void readP();
    void payment();
};

#endif