#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./include/Title.hh"
#include "./include/Time.hh"
#include "./include/R_L_Page.hh"

#include "./src/Title.cpp"
#include "./src/time.cpp"
#include "./src/R_L_Page.cpp"
#include "./src/SuperAdmin.cpp"
#include "./src/Admin.cpp"
#include "./src/Docters.cpp"
#include "./src/Register.cpp"
#include "./src/Login.cpp"
#include "./src/Ambulance.cpp"
#include "./src/Billing.cpp"
#include "./src/Driver.cpp"
#include "./src/Exit.cpp"
#include "./src/Nurses.cpp"
#include "./src/Patients.cpp"
#include "./src/addStaff.cpp"
#include "./src/OtherStaff.cpp"
#include "./src/address.cpp"
#include "./src/appointment.cpp"

// Time t;
// string Loc_date = t.get_date();
// string Loc_time = t.get_time();

/*------------------------------------------------------------------------------------*/
// Functions

void mainFunction();
void welcome_Screen();

/*------------------------------------------------------------------------------------*/

int main()
{
    clrscr();

    textbackground(YELLOW);
    textcolor(BLUE);

    mainFunction(); // Main Function Call

    getch();
    return 0;
}

/*------------------------------------------------------------------------------------*/

// Main Function Start
void mainFunction()
{

    clrscr();

    welcome_Screen(); // welcome_Screen Function Call

    clrscr();
    
    RLpage RL;
    RL.R_L_Page(); // R_L_Page Function Call

    getch();
} // Main Function end

/*------------------------------------------------------------------------------------*/

// welcome_Screen Function Start
void welcome_Screen()
{
    clrscr();

    cout << "\n\n\n\n\n\n\n\n";
    cout << "\n\n\t\t\t   ********************************************************************" << endl;
    cout << "\t\t\t   *\t\t\t\t\t\t\t\t      *\n";
    cout << "\t\t\t   *\t\t\tHOSPITAL MANAGEMENT SYSTEM"
         << "\t\t      *" << endl;
    cout << "\t\t\t   *\t\t\t\t\t\t\t\t      *\n";
    // cout << "\t\t\t   ********************************************************************" << endl;

    // cout << "\t\t\t   ********************************************************************" << endl;
    cout << "\t\t\t   *\t\t\t\t\t\t\t\t      *\n";
    cout << "\t\t\t   *\t\t    Software Engineering Project Report"
         << "\t\t      *" << endl;
    cout << "\t\t\t   *\t\t\t\t\t\t\t\t      *\n";
    cout << "\t\t\t   ********************************************************************" << endl;

    printf("\n\n\n\n\t\t\t\t\tPress any key to continue...............\t");

    getch();
}
// welcome_Screen Function end

/*------------------------------------------------------------------------------------*/