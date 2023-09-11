#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/Admin.hh"
#include "./../include/addStaff.hh"
#include "./../include/Nurses.hh"
#include "./../include/Driver.hh"
#include "./../include/Ambulance.hh"
#include "./../include/OtherStaff.hh"

void adStaff::addStaff()
{
r:
    clrscr();
    Title tt;
    tt.TitleS();

    cout << "\n\n\t1 << For Add Nurses" << endl;
    cout << "\t2 << For Add Drivers" << endl;
    cout << "\t3 << For Add Ambulance" << endl;
    cout << "\t4 << For Add Other Staff" << endl;
    cout << "\t5 << For Go Back" << endl;

    int chs;
    cout << "\n\t\tEnter your choice : ";
    cin >> chs;

    if (chs == 1)
    {
    b:
        clrscr();
        Title tt;
        tt.TitleS();

        Nurses ns;
        ns.input();

        char ch;
        cout << "\n\tDo you want to add more patient (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto b;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\tThank You \n";
            addStaff();
        }
        getch();
    }
    else if (chs == 2)
    {
    c:
        clrscr();
        Title tt;
        tt.TitleS();

        Drivers dr;
        dr.input();

        char ch;
        cout << "\n\tDo you want to add more patient (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto c;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\tThank You \n";
            addStaff();
        }
        getch();
    }
    else if (chs == 3)
    {
    d:
        clrscr();
        Title tt;
        tt.TitleS();

        Ambulance am;
        am.input();

        char ch;
        cout << "\n\tDo you want to add more patient (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto d;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\tThank You \n";
            addStaff();
        }
        getch();
    }
    else if (chs == 4)
    {
    e:
        clrscr();
        Title tt;
        tt.TitleS();

        othStaff_Class os;
        os.input();

        char ch;
        cout << "\n\tDo you want to add more patient (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto e;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\tThank You \n";
            addStaff();
        }
        getch();
    }

    else if (chs == 5)
    {
        SupAdmin Sup;
        Sup.SuperAdd();
    }
    else
    {
        cout << "\n\tWrong!. Please Choose right option :)" << endl;
        sleep(1);
        goto r;
    }
}

void adStaff::showStaff()
{
r:
    clrscr();
    Title tt;
    tt.TitleS();

    cout << "\n\n\t1 << For Nurses List" << endl;
    cout << "\t2 << For Drivers List" << endl;
    cout << "\t3 << For Ambulance List" << endl;
    cout << "\t4 << For Other Staff List" << endl;
    cout << "\t5 << For Go Back" << endl;

    int chs;
    cout << "\n\t\tEnter your choice : ";
    cin >> chs;

    if (chs == 1)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        ifstream nsIn;

        nsIn.open("./data/Nurses_list.csv", ios::in);

        if (nsIn.fail())
        {
            cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
            sleep(1);
            showStaff();
        }
        else
        {
            string dataReadp;
            while (!nsIn.eof())
            {
                getline(nsIn, dataReadp);
                cout << dataReadp << endl;
            }
            nsIn.close();

            getch();
            getch();
            sleep(1);
            showStaff();
        }
    }
    else if (chs == 2)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        ifstream drIn;

        drIn.open("./data/Drivers_list.csv", ios::in);

        if (drIn.fail())
        {
            cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
            sleep(1);
            showStaff();
        }
        else
        {
            string dataReadp;
            while (!drIn.eof())
            {
                getline(drIn, dataReadp);
                cout << dataReadp << endl;
            }
            drIn.close();

            getch();
            getch();
            sleep(1);
            showStaff();
        }
    }
    else if (chs == 3)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        ifstream amIn;

        amIn.open("./data/Ambulances_list.csv", ios::in);

        if (amIn.fail())
        {
            cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
            sleep(1);
            showStaff();
        }
        else
        {
            string dataReadp;
            while (!amIn.eof())
            {
                getline(amIn, dataReadp);
                cout << dataReadp << endl;
            }
            amIn.close();

            getch();
            getch();
            sleep(1);
            showStaff();
        }
    }
    else if (chs == 4)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        ifstream osIn;

        osIn.open("./data/OtherStaff_list.csv", ios::in);

        if (osIn.fail())
        {
            cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
            sleep(1);
            showStaff();
        }
        else
        {
            string dataReadp;
            while (!osIn.eof())
            {
                getline(osIn, dataReadp);
                cout << dataReadp << endl;
            }
            osIn.close();

            getch();
            getch();
            sleep(1);
            showStaff();
        }
    }

    else if (chs == 5)
    {
        SupAdmin Sup;
        Sup.SuperAdd();
    }
    else
    {
        cout << "\n\tWrong!. Please Choose right option :)" << endl;
        sleep(1);
        goto r;
    }
}