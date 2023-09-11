#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>

using namespace std;

#include "./../include/address.hh"

Address_class::Address_class()
{
    line1 = "";
    line2 = "";
    city = "";
    state = "";
    pinCode = "";
    country = "";
}

void Address_class::takeInput()
{
    cout << "\n\t\tEnter address : \n";
    cout << "\n\t\tLine 1 :- ";
    getline(cin >> ws, line1);
    cout << "\n\t\tLine 2 (optional) :- ";
    getline(cin, line2);
    cout << "\n\t\tCity :- ";
    getline(cin >> ws, city);
    cout << "\n\t\tState :- ";
    getline(cin >> ws, state);
    cout << "\n\t\tPin Code :- ";
    getline(cin >> ws, pinCode);
    cout << "\n\t\tCountry :- ";
    getline(cin >> ws, country);

    cout << endl;

    return;
}

void Address_class::print()
{
    cout << "Line 1: " << line1 << "\n";
    if (line2 != "")
        cout << "\t\t"
             << "Line 2: " << line2 << "\n";
    cout << "\t\t";
    cout << "City: " << city << "\n";
    cout << "\t\t";
    cout << "State: " << state << "\n";
    cout << "\t\t";
    cout << "Pin Code: " << pinCode << "\n";
    cout << "\t\t";
    cout << "Country: " << country << "\n";

    return;
}
string Address_class::addToStr()
{
    stringstream s;
    s << line1 << "`" << line2 << "`" << city << "`" << state << "`" << pinCode << "`" << country;
    string add;
    getline(s, add);
    // for (auto &i : add)
    // if (i == ',')
    // i = '^';
    return add;
}
void Address_class::strToAdd(string str)
{
    stringstream s(str);

    getline(s, line1, ',');
    for (auto &i : line1)
        if (i == ',')
            i = ',';

    getline(s, line2, ',');
    for (auto &i : line2)
        if (i == ',')
            i = ',';

    getline(s, city, ',');
    getline(s, state, ',');
    getline(s, pinCode, ',');
    getline(s, country, ',');
    return;
}

// int main()
// {
//     // ofstream out;
//     // out.open("../data/address.csv", ios::app);

//     // if (!out)
//     // {
//     //     cout << "\t\tnot" << endl;
//     // }

//     Address_class a;

//     // a.takeInput();
//     // string p = a.addToStr();
//     // out << p << endl;

//     // out.close();

//     ifstream in;
//     in.open("../data/address.csv", ios::in);

//     if (!in)
//     {
//         cout << "\t\tnot" << endl;
//     }

//     string line;
//     getline(in, line);
//     a.strToAdd(line);
//     a.print();

//     // a.strToAdd();

//     return 0;
// }