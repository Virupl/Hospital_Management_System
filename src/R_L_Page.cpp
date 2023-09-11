#include <iostream>
#include <conio.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/R_L_Page.hh"
#include "./../include/Register.hh"
#include "./../include/Login.hh"

//  R_L_Page Function Start
void RLpage::R_L_Page()
{
r:
    clrscr();

    Title tt;
    tt.TitleS();

    int choice;
    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n\n"
         << endl;
    cout << "\t\t1 << For Registration" << endl;
    cout << "\t\t2 << For Login" << endl;

    cout << "\n\t\tEnter your choice : ";
    cin >> choice;

    if (choice == 1)
    {
        regis regst;
        regst.Registration();
    }
    else if (choice == 2)
    {
        login lg;
        lg.Login();
    }
    else
    {
        cout << "\n\t\tChoose Right Option" << endl;
        sleep(1);
        goto r;
    }

    getch();
} // R_L_Page Function end