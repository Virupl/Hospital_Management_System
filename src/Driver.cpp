#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Driver.hh"
#include "./../include/addStaff.hh"
#include "./../include/address.hh"

string Drivers::lastlineReadCSV()
{
    string line, lastLine;
    ifstream infile;
    string filename = "./data/Drivers_list.csv";
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

void Drivers::input()
{
    ofstream DrFile;

    DrFile.open("./data/Drivers_list.csv", ios::app);

    if (!DrFile)
    {
        cout << "\nError while opening the file\n";
        sleep(1);

        adStaff ads;
        ads.addStaff();
    }
    else
    {
        string ID = lastlineReadCSV();

        cout << "\n\t\t\t NURSES DETAILS"
             << endl;
        // cout << "\tEnter ID : ";
        // cin >> ID;
        cout << "\n\t\tEnter First Name :- ";
        cin >> FirstName;
        cout << "\t\tEnter Last Name :- ";
        cin >> LastName;

        cout << "\t\tEnter Age :- ";
        cin >> Age;
        if (Age < minAge || Age > maxAge)
        {
            return void(cout << "\n\tSorry, Your age is Less than 18 and grather than 65. \n");
            sleep(1);
        }

        cout << "\t\tEnter Gender :- ";
        cin >> Gender;
        while (Gender != 'M' && Gender != 'F')
        {
            cout << "\t\tM or F? : ";
            cin >> Gender;
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

        cout << "\t\tEnter The Date Of Joining The Hospital (DATE/MONTH/YEAR) :- ";
        cin >> JoinDate;
        // cout << "\t\tEnter Address :- ";
        // cin >> Address;
        Address_class add;
        add.takeInput();
        Address = add.addToStr();

        // string headerData = "NurseID,First Name,Last Name,Age,Gender,Mobile_no,Address,Joining Date";
        // NsFile << headerData << endl;
        DrFile << ID << "," << FirstName << "," << LastName << "," << Age << "," << Gender << "," << Mobile_no << "," << Address << "," << JoinDate << endl;

        cout << "\nInformation Saved Successfully\n";

        DrFile.close();

        getch();
    }
}