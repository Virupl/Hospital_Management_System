#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/R_L_Page.hh"
#include "./../include/Docters.hh"
#include "./../include/SuperAdmin.hh"
#include "./../include/address.hh"

// Login_Docter Function Start
void Doctor::Login_Doctor()
{
    clrscr();

    Title tt;
    tt.TitleS(); // Title Function Call

    char original_Id[20], original_Password[20];
    char temp_Id[20], temp_Password[20];

    ifstream dctIn;

    string lineRead;

repeat:
    cout << "\tEnter your ID : ";
    cin >> temp_Id;
    cout << "\tEnter your Password : ";
    cin >> temp_Password;

    dctIn.open("./data/Admin.txt", ios::in);
    RLpage RL;
    if (dctIn.fail())
    {
        cout << "\n\tFile failed to open. Please register fisrt then Login." << endl;
        sleep(1);
        RL.R_L_Page();
    }

    dctIn >> original_Id >> original_Password;

    if (strcmp(temp_Id, original_Id) == 0 && strcmp(temp_Password, original_Password) == 0)
    {
        cout << "\n\t\tLogin successful\n\n";

        sleep(1);

        clrscr();

        Title tt;
        tt.TitleS();
    }
    else
    {
        cout << "\n\t\tLogin error\n\n";
    }

    dctIn.close();

} // Login_Docter Function end

string Doctor::lastlineReadCSV()
{
    string line, lastLine;
    ifstream infile;
    string filename = "./data/Doctors_list.csv";
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

void Doctor::input()
{
    ofstream dtFile;

    clrscr();

    Title tt;
    tt.TitleS();

    dtFile.open("./data/Doctors_list.csv", ios::app);

    if (!dtFile)
    {
        cout << "\nError while opening the file\n";
        sleep(1);
        SupAdmin Sup;
        Sup.SuperAdd();
    }
    else
    {
        string ID = lastlineReadCSV();

        cout << "\n\t\t\t DOCTOR DETAILS"
             << endl;
        // cout << "\tEnter ID : ";
        // cin >> ID;
        cout << "\n\t\tEnter First Name :- ";
        cin >> FirstName;

        cout << "\t\tEnter Last Name :- ";
        cin >> LastName;

        cout << "\t\tEnter Gender (M for male / F for Female) :- ";
        cin >> gender;
        while (gender != 'M' && gender != 'F')
        {
            cout << "\t\tM or F? : ";
            cin >> gender;
        }

        cout << "\t\tEnter Age :- ";
        cin >> age;
        if (age < minAge || age > maxAge)
        {
            return void(cout << "\n\tSorry, Your age is Less than 18 and grather than 65. \n");
            sleep(1);
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

        // string headerData = "DocterID,First Name,Last Name,Gender,Age,Mobile_no,Address,Joining Date";
        // dtFile << headerData << endl;
        // string rowData = ID + "," + FirstName + "," + LastName + "," + gender + "," + age + "," + Mobile_no + "," + Address + "," + JoinDate;

        // dtFile << rowData << endl;
        dtFile << ID << "," << FirstName << "," << LastName << "," << gender << "," << age << "," << Mobile_no << "," << Address << "," << JoinDate << endl;

        cout << "\nInformation Saved Successfully\n";

        dtFile.close();

        getch();
    }
}

void Doctor::printDetails()
{

    ifstream infile;

    cout << "\nDetails:\n";
    // cout << "ID              : " << id << "\n";
    cout << "Full Name       : " << FirstName << " " << LastName << "\n";
    cout << "Gender          : " << gender << "\n";
    cout << "Age             : " << age << "\n";
    cout << "Mobile          : " << Mobile_no << "\n";
    cout << "Address         : ";
    Address_class add;
    add.print();
    return;
}

void Doctor::removeDocter()
{
    ifstream fin;
    ofstream fout;
    ofstream reout;

    fin.open("./data/Doctors_list.csv", ios::in);
    fout.open("./data/temp.csv", ios::out);
    reout.open("./data/DocterRemove.csv", ios::app);
    if (fin.fail())
    {
        cout << "File open Failed" << endl;
        sleep(1);
        SupAdmin s;
        s.SuperAdd();
    }

    string line, first_word, match, reDate;
    vector<string> lines;

    cout << "\n\t\tEnter Docter ID :- ";
    cin >> match;
    cout << "\n\t\tEnter Today Date (DD/MM/YYYY) :- ";
    cin >> reDate;

    // Read the lines from the file into a vector
    while (getline(fin, line))
    {
        first_word = line.substr(0, line.find(","));
        if (first_word != match)
        {
            lines.push_back(line);
        }
        if (first_word == match)
        {
            cout << line << endl;
            reout << line << "," << reDate << endl;
            reout.close();
        }
    }
    fin.close();
    remove("./data/Doctors_list.csv");

    for (const auto &l : lines)
    {
        fout << l << endl;
    }

    rename("./data/temp.csv", "./data/Doctors_list.csv");
    fout.close();
}