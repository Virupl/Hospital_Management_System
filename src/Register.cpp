#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/Admin.hh"
#include "./../include/R_L_Page.hh"
#include "./../include/Register.hh"

// Registration Function Start
void regis::Registration()
{
RGTN:
    clrscr();

    Title tt;
    tt.TitleS(); // Title Function Call

    int ADP_choice;

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n\n"
         << endl;
    cout << "\t\t1 << For Super Admin Registration" << endl;
    cout << "\t\t2 << For Admin Registration" << endl;
    cout << "\t\t3 << Go Back" << endl;

    cout << "\n\t\tEnter your choice : ";
    cin >> ADP_choice;

    if (ADP_choice == 1)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        Sup_Admin sp;
        sp.input();
    }
    else if (ADP_choice == 2)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        Admin a;
        a.input();
    }
    else if (ADP_choice == 3)
    {
        RLpage RL;
        RL.R_L_Page();
    }
    else
    {
        cout << "\n\t\tChoose Right Option" << endl;
        sleep(1);
        goto RGTN;
    }
} // Registration Function end