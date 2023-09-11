#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/Patients.hh"
#include "./../include/Admin.hh"
#include "./../include/address.hh"

string patient::lastlineReadCSV()
{
    string line, lastLine;
    ifstream infile;
    string filename = "./data/Patients_list.csv";
    infile.open(filename);

    if (infile.is_open())
    {
        char ch;
        infile.seekg(-1, ios::end); // move to location 65
        infile.get(ch);             // get next char at loc 66
        if (ch == '\n')
        {
            infile.seekg(-2, ios::cur); // move to loc 64 for get() to read loc 65
            infile.seekg(-1, ios::cur); // move to loc 63 to avoid reading loc 65
            infile.get(ch);             // get the char at loc 64 ('5')
            while (ch != '\n')          // read each char backward till the next '\n'
            {
                infile.seekg(-2, ios::cur);
                infile.get(ch);
            }

            getline(infile, lastLine);
            // cout << "The last line : " << lastLine << '\n';
        }
    }

    lastLine.resize(4);
    int num = stoi(lastLine);
    // cout << num << endl;
    string newdata;
    num++;
    newdata = to_string(num);
    // cout << newdata << endl;

    return newdata;
}

void patient::input()
{
    ofstream ptFile;

    clrscr();

    Title tt;
    tt.TitleS();

    ptFile.open("./data/Patients_list.csv", ios::app);

    if (!ptFile)
    {
        cout << "\nError while opening the file\n";
        sleep(1);
        Admin ad;
        ad.AdminAdd();
    }
    else
    {
        string ID = lastlineReadCSV();

        cout << "\n\t\t\t PATIENT DETAILS"
             << endl;
        // cout << "\tEnter ID : ";
        // cin >> ID;
        cout << "\n\t\tEnter First Name :- ";
        cin >> FirstName;

        cout << "\t\tEnter Last Name :- ";
        cin >> LastName;

        cout << "\t\tEnter Gender (M for male / F for Female) :- ";
        cin >> Gender;
        while (Gender != 'M' && Gender != 'F')
        {
            cout << "\t\tM or F? : ";
            cin >> Gender;
        }
    ag:
        cout << "\t\tEnter Age :- ";
        cin >> age;
        if (age < 0)
        {
            cout << "Please, Enter Right Age";
            sleep(1);
            goto ag;
        }

    m:
        cout << "\t\tEnter Mobile No :- ";
        cin >> Mobile_no;
        int SIZE = Mobile_no.length();
        if (SIZE > 12 || SIZE < 10)
        {
            cout << "\n\t Only 10 Digit Mobile No. Valid. Please Enter Right Number" << endl;
            sleep(1);
            goto m;
        }

        cout << "\t\tEnter Blood Group :- ";
        cin >> BG;

        Address_class add;
        add.takeInput();
        Address = add.addToStr();

        cout << "\t\tEnter Today Date (DATE/MONTH/YEAR) :- ";
        cin >> Date;

        // string headerData = "PatientID,First Name,Last Name,Gender,Age,Mobile_no,Blood Group,Address,Admit Date";
        // ptFile << headerData << endl;
        ptFile << ID << "," << FirstName << "," << LastName << "," << Gender << "," << age << "," << Mobile_no << "," << BG << "," << Address << "," << Date << endl;

        cout << "\nInformation Saved Successfully\n";

        ptFile.close();

        getch();
    }
}