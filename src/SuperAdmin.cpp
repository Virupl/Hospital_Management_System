#include <iostream>
#include <conio.h>
// #include <string>
#include <fstream>
#include <string.h>
#include <time.h>

#include "./../include/Title.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/Admin.hh"
#include "./../include/R_L_Page.hh"
#include "./../include/Docters.hh"
#include "./../include/addStaff.hh"
#include "./../include/Exit.hh"
#include "./../include/address.hh"

using namespace std;

void Sup_Admin::input()
{
a:
    ofstream SupAdFile;
    ofstream file_IdP;

    clrscr();

    Title tt;
    tt.TitleS();

    SupAdFile.open("./data/SuperAdminData.txt", ios::out);
    file_IdP.open("./data/SuperAdminIDP.txt", ios::out);

    if (!SupAdFile)
    {
        cout << "\nError while opening the file\n";
        sleep(1);
        RLpage RL;
        RL.R_L_Page();

        if (!file_IdP)
        {
            cout << "\nError while opening the file\n";
            RL.R_L_Page();
        }
    }
    else
    {
        SupAdFile << "\n********************************************************************\n\n";
        cout << "\n\t\t\t SUPER ADMIN DETAILS"
             << "\n";
        SupAdFile << "\n\t\t\t SUPER ADMIN DETAILS"
                  << endl;

        cout << "\n\tEnter Full Name :- ";
        cin.ignore();
        fgets(name, 50, stdin);
        SupAdFile << "\tFull Name : ";
        SupAdFile << name << endl;

        cout << "\tEnter Mobile No :- ";
        fgets(Mobile_no, 15, stdin);
        SupAdFile << "\tMobile No : ";
        SupAdFile << Mobile_no << endl;

        // cout << "\tEnter Address :- ";
        Address_class add;
        add.takeInput();
        string str = add.addToStr();
        SupAdFile << "\tAddress : ";
        SupAdFile << str << endl;

        cout << "\tEnter ID : ";
        fgets(ID, 20, stdin);
        file_IdP << ID << endl;

        cout << "\tEnter Password : ";
        fgets(Password, 20, stdin);
        file_IdP << Password << endl;
        SupAdFile << "\n********************************************************************\n\n";

        cout << "\nInformation Saved Successfully\n";

        SupAdFile.close();

        getch();
        RLpage RL;
        RL.R_L_Page();
    }
}
// Login Super Admin Function Start
void SupAdmin::Login_Sup_Admin()
{
    clrscr();

    Title tt;
    tt.TitleS(); // Title Function Call

    char original_Id[20], original_Password[20];
    char temp_Id[20], temp_Password[20];

    ifstream SupIn;

repeat:
    cout << "\tEnter your ID : ";
    cin >> temp_Id;

    cout << "\tEnter your Password : ";
    cin >> temp_Password;

    SupIn.open("./data/SuperAdminIDP.txt", ios::in);

    if (SupIn.fail())
    {
        cout << "\n\tFile failed to open. Please register fisrt then Login." << endl;
        RLpage RL;
        RL.R_L_Page();
    }

    SupIn >> original_Id >> original_Password;

    if (strcmp(temp_Id, original_Id) == 0 && strcmp(temp_Password, original_Password) == 0)
    {
        cout << "\n\t\tLogin successful\n\n";

        sleep(1);

        clrscr();

        // Title();
        SupAdmin Sup;
        Sup.SuperAdd();
    }
    else
    {
        cout << "\n\tWrong Id and Password, Please try again. \n\n";
        goto repeat;
    }

    SupIn.close();

} // Login Super Admin Function end

/*------------------------------------------------------------------------------------*/

// SuperAdd function Start
void SupAdmin::SuperAdd()
{

r:
    clrscr();
    Title tt;
    tt.TitleS();

    int S_choice;

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n\n"
         << endl;
    cout << "\t\t1 << For Add Docter" << endl;
    cout << "\t\t2 << For Docter List" << endl;
    cout << "\t\t3 << For Docter Remove" << endl;
    cout << "\t\t4 << For Admin Data" << endl;
    cout << "\t\t5 << For Patient Data" << endl;
    cout << "\t\t6 << For Add Staff" << endl;
    cout << "\t\t7 << For Staff List" << endl;
    cout << "\t\t8 << For Exit" << endl;

    cout << "\n\t\tEnter your choice : ";
    cin >> S_choice;

    if (S_choice == 1)
    {
    a:
        clrscr();
        Title tt;
        tt.TitleS();

        Doctor d;
        d.input();

        char ch;
        cout << "\n\tDo you want to add more docter (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto a;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\tThank You \n";
            SuperAdd();
        }
        getch();
    }
    else if (S_choice == 2)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        ifstream dctIn;

        dctIn.open("./data/Doctors_list.csv", ios::in);

        if (dctIn.fail())
        {
            cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
            sleep(1);
            SuperAdd();
        }
        else
        {
            string dataRead;
            while (!dctIn.eof())
            {
                getline(dctIn, dataRead);
                cout << dataRead << endl;
            }
            dctIn.close();

            getch();
            getch();
            sleep(1);
            SuperAdd();
        }
    }
    else if (S_choice == 3)
    {
    dt:
        clrscr();
        Title tt;
        tt.TitleS();

        Doctor d;
        d.removeDocter();

        char ch;
        cout << "\n\tDo you want to remove more docter (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto dt;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\tThank You \n";
            SuperAdd();
        }

        getch();
    }

    else if (S_choice == 4)
    {
    c:
        clrscr();
        Title tt;
        tt.TitleS();

        ifstream AdIn;

        AdIn.open("./data/Admin.txt", ios::in);
        if (AdIn.fail())
        {
            cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
            // getch();
            sleep(1);
            goto c;
        }
        else
        {
            string dataRead;
            while (!AdIn.eof())
            {
                getline(AdIn, dataRead);
                cout << dataRead << endl;
            }

            getch();

            AdIn.close();

            char ch;
            cout << "\n\tDo you want to exit (Y/N) : ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y')
            {
                cout << "\n\tThank You :) :) \n";
                sleep(1);
                SuperAdd();
            }
            if (ch == 'n' || ch == 'N')
            {
                sleep(1);
                goto c;
            }

            getch();
        }
    }
    else if (S_choice == 5)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        ifstream ptIn;

        ptIn.open("./data/Patients_list.csv", ios::in);

        if (ptIn.fail())
        {
            cout << "\n\tFile failed to open. Please Enter right file name. " << endl;
            sleep(1);
            SuperAdd();
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
            getch();
            sleep(1);
            SupAdmin Sup;
            Sup.SuperAdd();
        }
    }
    else if (S_choice == 6)
    {
        adStaff ads;
        ads.addStaff();
    }
    else if (S_choice == 7)
    {
        adStaff adsw;
        adsw.showStaff();
    }
    else if (S_choice == 8)
    {
        exite ex;
        ex.Exit();
    }
    else
    {
        cout << "\n\tWrong!. Please Choose right option :)" << endl;
        sleep(1);
        goto r;
    }

} // SuperAdd function end
