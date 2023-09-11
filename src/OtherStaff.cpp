#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/addStaff.hh"
#include "./../include/OtherStaff.hh"
#include "./../include/address.hh"

string othStaff_Class::lastlineReadCSV()
{
    string line, lastLine;
    ifstream infile;
    string filename = "./data/Ambulances_list.csv";
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

void othStaff_Class::input()
{

    ofstream osFile;

    osFile.open("./data/OtherStaff_list.csv", ios::app);

    if (!osFile)
    {
        cout << "\nError while opening the file\n";
        sleep(1);

        adStaff ads;
        ads.addStaff();
    }
    else
    {
        string ID = lastlineReadCSV();

        cout << "\n\n\t\t OTHER STAFF DETAILS"
             << endl;
        cout << "\n\tEnter First Name :- ";
        cin >> FirstName;
        cout << "\tEnter Last Name :- ";
        cin >> LastName;

        cout << "\tEnter Age :- ";
        cin >> Age;
        if (Age < minAge || Age > maxAge)
        {
            return void(cout << "\n\tSorry, Your age is Less than 18 and grather than 65. \n");
            sleep(1);
        }

        cout << "\tEnter Gender :- ";
        cin >> Gender;
        while (Gender != 'M' && Gender != 'F')
        {
            cout << "\t\tM or F? : ";
            cin >> Gender;
        }

    m:
        cout << "\tEnter Mobile No :- ";
        cin >> Mobile_no;
        int SIZE = Mobile_no.length();
        if (SIZE > 12 || SIZE < 10)
        {
            cout << "\n\t Only 10 Digit Mobile No. Valid. Please Enter Right Number" << endl;
            sleep(1);
            goto m;
        }

        cout << "\tEnter The Date Of Joining The Hospital (DATE/MONTH/YEAR) :- ";
        cin >> JoinDate;

        cout << "\tEnter Department Name :- ";
        cin >> Department;

        // cout << "\tEnter Address :- ";
        // cin >> Address;
        Address_class add;
        add.takeInput();
        Address = add.addToStr();

        // string headerData = "StaffID,First Name,Last Name,Age,Gender,Mobile No,Address,Joining Date,Department Name";
        // osFile << headerData << endl;
        osFile << ID << "," << FirstName << "," << LastName << "," << Age << "," << Gender << "," << Mobile_no << "," << Address << "," << JoinDate << "," << Department << endl;

        cout << "\nInformation Saved Successfully\n";

        osFile.close();

        getch();
    }
}