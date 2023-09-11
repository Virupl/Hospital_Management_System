#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/Admin.hh"
#include "./../include/Billing.hh"
#include "./../include/Time.hh"

Time t;
string Loc_date = t.get_date();
string Loc_time = t.get_time();

void Billing::readP()
{
    ifstream ptIn;

    ptIn.open("./data/Patients_list.csv", ios::in);

    if (ptIn.fail())
    {
        cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
        sleep(1);
        SupAdmin Sup;
        Sup.SuperAdd();
    }
    else
    {
        string dataReadp;
        while (!ptIn.eof())
        {
            getline(ptIn, dataReadp);
            cout << dataReadp << endl;
        }
        ptIn.close();

        getch();
    }
}
void Billing::payment()
{
r:
    struct bill bl;

    cout << "\n\n\t\t\t Payment Mode" << endl;
    cout << "\t1 << For Cash Payment" << endl;
    cout << "\t2 << For Credit card Payment (Coming Soon)" << endl;
    cout << "\t3 << For Debit card Payment (Coming Soon)" << endl;
    cout << "\t4 << For Go Back" << endl;

    int i;
    cout << "\n\t\t<Enter mode of payment : ";
    cin >> i;

    if (i == 1)
    {
    a:
        readP();

        cout << "\n\n\t\t\tCash Payment" << endl;
        cout << "\n\tEnter Patient Id :- ";
        cin >> bl.pID;
        cout << "\tEnter First Name :- ";
        cin >> bl.pfname;
        cout << "\tEnter Last Name :- ";
        cin >> bl.plname;
        cout << "\tEnter Amount :- ";
        cin >> bl.payment;

        ofstream pmtOut;
        pmtOut.open("./data/payment.csv", ios::app);

        // string headerData = "PatiendID,First Name,Last Name,Payment,Time,Date";
        // pmtOut << headerData << endl;
        pmtOut << bl.pID << "," << bl.pfname << "," << bl.plname << "," << bl.payment << "," << Loc_time << "," << Loc_date << endl;

        cout << "\n\t\tPayment Successfully Done! :)" << endl;

        getch();

        char ch;
        cout << "\n\tDo you want to more payment (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto a;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\t\tThank You :)" << endl;
            sleep(1);
            Admin ad;
            ad.AdminAdd();
        }
        getch();
    }
    else if (i == 4)
    {
        sleep(1);
        Admin ad;
        ad.AdminAdd();
    }
    else
    {
        cout << "\n\tWrong!. Please Choose right option :)" << endl;
        sleep(1);
        goto r;
    }

    getch();
}