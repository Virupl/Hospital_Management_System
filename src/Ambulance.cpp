#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

#include "./../include/Ambulance.hh"
#include "./../include/addStaff.hh"

string Ambulance::lastlineReadCSV()
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
void Ambulance::input()
{
    ofstream AmFile;

    AmFile.open("./data/Ambulances_list.csv", ios::app);

    if (!AmFile)
    {
        cout << "\nError while opening the file\n";
        sleep(1);

        adStaff ads;
        ads.addStaff();
    }
    else
    {
        string ID = lastlineReadCSV();

        cout << "\n\n\t\t AMBULANCE DETAILS"
             << endl;
        cout << "\t\tEnter Model of the ambulance :- ";
        cin >> Model;
        cout << "\t\tEnter Manufacturer Name of the ambulance :- ";
        cin >> Manufacturer;
        cout << "\t\tEnter Vehicle Registration Number of the ambulance :- ";
        cin >> Vrn;

        // string headerData = "AmbulaceID,Model,Manufacturer,Vehicle Reg. No.";
        // AmFile << headerData << endl;
        AmFile << ID << "," << Model << "," << Manufacturer << "," << Vrn << endl;

        cout << "\nInformation Saved Successfully\n";

        AmFile.close();

        getch();
    }
}