#include <iostream>
#include <conio.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/R_L_Page.hh"
#include "./../include/Exit.hh"

// Exit Function Start
void exite::Exit()
{
    clrscr();
    Title tt;
    tt.TitleS();

    cout << "\n\tThank You :) :) \n";
    sleep(1);
    RLpage RL;
    RL.R_L_Page();
}