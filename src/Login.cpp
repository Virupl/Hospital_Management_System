#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

#include "./../include/Title.hh"
#include "./../include/Time.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/Admin.hh"
#include "./../include/R_L_Page.hh"
#include "./../include/Login.hh"
#include "./../include/Docters.hh"

using namespace std;

// Login Function Start
void login::Login()
{
LO:
    clrscr();

    Title tt;
    tt.TitleS(); // Title Function Call

    int L_choice;

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n\n"
         << endl;
    cout << "\t\t1 << For Super Admin Login" << endl;
    cout << "\t\t2 << For Admin Login" << endl;
    cout << "\t\t3 << For Doctor Login" << endl;
    cout << "\t\t4 << Go Back" << endl;

    cout << "\n\t\tEnter your choice : ";
    cin >> L_choice;

    if (L_choice == 1)
    {
        SupAdmin Sup;
        Sup.Login_Sup_Admin();
    }
    else if (L_choice == 2)
    {
        Admin ad;
        ad.Login_Admin();
    }
    else if (L_choice == 3)
    {
        Doctor dc;
        dc.Login_Doctor();
    }
    else if (L_choice == 4)
    {
        RLpage RL;
        RL.R_L_Page();
    }
    else
    {
        cout << "\n\t\tChoose Right Option" << endl;
        goto LO;
    }
} // Login Function end
