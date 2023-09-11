#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/Time.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/R_L_Page.hh"
#include "./../include/Admin.hh"
#include "./../include/Patients.hh"
#include "./../include/Billing.hh"
#include "./../include/Exit.hh"
#include "./../include/addStaff.hh"
#include "./../include/address.hh"
#include "./../include/appointment.hh"

void Admin::input()
{
a:
    ofstream adFile;
    ofstream file_IdP;
    clrscr();

    Title tt;
    tt.TitleS();

    adFile.open("./data/Admin.txt", ios::out);
    file_IdP.open("./data/AdminIDP.txt", ios::out);

    if (!adFile)
    {
        cout << "\nError while opening the file\n";
        goto a;

        if (!file_IdP)
        {
            cout << "\nError while opening the file\n";
            goto a;
        }
    }
    else
    {
        adFile << "\n********************************************************************\n\n";
        cout << "\n\t\t\t ADMIN DETAILS"
             << "\n";
        adFile << "\n\t\t\t ADMIN DETAILS"
               << endl;
        cout << "\n\tEnter Full Name :- ";
        cin.ignore();
        fgets(name, 50, stdin);
        adFile << "\tFull Name : ";
        adFile << name << endl;

        cout << "\tEnter Mobile No :- ";
        fgets(Mobile_no, 15, stdin);
        adFile << "\tMobile No : ";
        adFile << Mobile_no << endl;

        // cout << "\tEnter Address :- ";
        Address_class add;
        add.takeInput();
        string str = add.addToStr();
        adFile << "\tAddress : ";
        adFile << str << endl;

        cout << "\tEnter ID : ";
        fgets(ID, 20, stdin);
        file_IdP << ID << endl;

        cout << "\tEnter Password : ";
        fgets(Password, 20, stdin);
        file_IdP << Password << endl;
        adFile << "\n********************************************************************\n\n";

        cout << "\nInformation Saved Successfully\n";

        adFile.close();

        getch();
        RLpage RL;
        RL.R_L_Page();
    }
}
// AdminAdd function Start
void Admin::AdminAdd()
{
r:
    clrscr();
    Title tt;
    tt.TitleS();

    int A_choice;

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n\n"
         << endl;
    cout << "\t\t1 << For Add Patient" << endl;
    cout << "\t\t2 << For Book Appointment" << endl;
    cout << "\t\t3 << For Docter List" << endl;
    cout << "\t\t4 << For Patient List" << endl;
    cout << "\t\t5 << For Bill Generate" << endl;
    cout << "\t\t6 << For Exit" << endl;

    cout << "\n\t\tEnter your choice : ";
    cin >> A_choice;

    if (A_choice == 1)
    {
    a:
        clrscr();
        Title tt;
        tt.TitleS();

        patient p;
        p.input();

        char ch;
        cout << "\n\tDo you want to add more patient (Y/N) : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            goto a;
        }
        if (ch == 'n' || ch == 'N')
        {
            cout << "\n\tThank You \n";
            AdminAdd();
        }
        getch();
    }
    else if (A_choice == 2)
    {
    q:
        clrscr();
        Title tt;
        tt.TitleS();

        cout << "\n\n\n\t\tPlease, Choose from the following Option:\n\n"
             << endl;
        cout << "\t\t1 << For Book an appointment " << endl;
        // cout << "\t\t2 << For Get appointment details" << endl;
        cout << "\t\t2 << For Show all appointments" << endl;
        int bk;
        cout << "\n\t\tEnter your choice : ";
        cin >> bk;

        if (bk == 1)
        {
        ap:
            clrscr();
            Title tt;
            tt.TitleS();

            appointment a;
            a.book();

            char ch;
            cout << "\n\tDo you want to add more appointment (Y/N) : ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y')
            {
                goto ap;
            }
            if (ch == 'n' || ch == 'N')
            {
                cout << "\n\tThank You \n";
                AdminAdd();
            }

            getch();
        }
        else if (bk == 2)
        {
            clrscr();
            Title tt;
            tt.TitleS();

            appointment a;
            a.showallAp();

            getch();
            getch();
            sleep(1);
            AdminAdd();
        }
        else
        {
            cout << "\n\tWrong!. Please Choose right option :)" << endl;
            sleep(1);
            goto q;
        }
    }
    else if (A_choice == 3)
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
            SupAdmin Sup;
            Sup.SuperAdd();
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
            AdminAdd();
        }
    }
    else if (A_choice == 4)
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
            getch();
            sleep(1);
            AdminAdd();
        }
    }
    else if (A_choice == 5)
    {
        clrscr();
        Title tt;
        tt.TitleS();

        Billing blp;
        blp.payment();
    }
    else if (A_choice == 6)
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

} // AdminAdd function end

/*------------------------------------------------------------------------------------*/

// Login_Admin Function Start
void Admin::Login_Admin()
{
    clrscr();

    Title tt;
    tt.TitleS(); // Title Function Call

    char original_Id[20], original_Password[20];
    char temp_Id[20], temp_Password[20];

    // original_Id = "Viru123",
    // original_Password = "8090";
    ifstream AdmIn;

repeat:
    cout << "\tEnter your ID : ";
    cin >> temp_Id;
    cout << "\tEnter your Password : ";
    cin >> temp_Password;

    AdmIn.open("./data/AdminIDP.txt", ios::in);

    if (AdmIn.fail())
    {
        cout << "\n\tFile failed to open. Please register fisrt then Login." << endl;
        RLpage RL;
        RL.R_L_Page();
    }

    AdmIn >> original_Id >> original_Password;

    if (strcmp(temp_Id, original_Id) == 0 && strcmp(temp_Password, original_Password) == 0)
    {
        cout << "\n\t\tLogin successful\n\n";

        sleep(1);

        clrscr();

        Title();

        AdminAdd();
    }
    else
    {
        cout << "\n\tWrong Id and Password, Please try again. \n\n";
        goto repeat;
    }

    AdmIn.close();
} // Login_Admin Function end
