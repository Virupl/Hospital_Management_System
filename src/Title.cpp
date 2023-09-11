#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Title.hh"

// Title Function Start
void Title::TitleS()
{

    cout << "\n\n\t\t\tHospital Management System\n\n";

    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char *dt = ctime(&now);

    cout << "\n  Date and time: " << dt << endl
         << endl;

    // cout << Loc_date << endl;
    // cout << Loc_time << endl;

} // Title Function end