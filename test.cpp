#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <string.h>
#include <thread>
using namespace std;

void read_record();

void readData();

void lastLineReadText();

string lastlineReadCSV();

int power(int n, int exp);
int strToNum(string s);

string getID();
string Last_str_word(const string &text);

void DocterDelete();

int main()
{
    // ofstream file;

    // file.open(".././data/_list.csv");
    // file << "Column1, Column2, Column3" << endl;
    // file << "1, 2, 3" << endl;
    // file << "4, 5, 6" << endl;
    // file << "7, 8, 9" << endl;
    // file.close();

    // read_record();

    // readData();

    // lastLineReadText();
    // string data = lastlineReadCSV();
    // cout << data << endl;

    // string id = getID();
    // cout << id << endl;
    // int n = stoi(id);
    // n++;
    // cout << n << endl;

    // ofstream onfile;
    // string filename = "./test.csv";
    // onfile.open(filename, ios::app);

    // if (onfile.is_open())
    // {
    //     onfile << n << ",";
    // }

    DocterDelete();

    // string str = "1";
    // int i = strToNum(str);
    // cout << i << endl;

    // string Mobile_no = "123456";
    // int SIZE = Mobile_no.length();
    // cout << SIZE << endl;

    // string ID = "1001";
    // int num = stoi(ID);
    // num = num + 1;
    // cout << num << endl
    // ID = to_string(num);
    // cout << ID << endl;

    // cout << "\t\t5 << For Add Nurses" << endl;
    // cout << "\t\t6 << For Add Drivers" << endl;
    // cout << "\t\t7 << For Add Ambulance" << endl;
    // cout << "\t\t9 << For Nurses List" << endl;
    // cout << "\t\t10 << For Drivers List" << endl;
    // cout << "\t\t11 << For Ambulance List" << endl;

    return 0;
}

void read_record()
{

    // File pointer
    fstream fin;

    // Open an existing file
    fin.open(".././data/Patients_list.csv", ios::in);

    // Get the roll number
    // of which the data is required
    int rollnum, roll2, count = 0;
    cout << "Enter the roll number "
         << "of the student to display details: ";
    cin >> rollnum;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;

    while (fin >> temp)
    {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        roll2 = std::stoi(row[0]);

        // Compare the roll number
        if (roll2 == rollnum)
        {

            // Print the found data
            count = 1;
            cout << "Details of Roll " << row[0] << " : \n";
            cout << "Name: " << row[1] << "\n";
            cout << "Maths: " << row[2] << "\n";
            cout << "Physics: " << row[3] << "\n";
            cout << "Chemistry: " << row[4] << "\n";
            cout << "Biology: " << row[5] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}

void readData()
{
    ifstream myFile;
    myFile.open(".././data/Patients_list.csv");
    string line;
    int n = 4; // desired row number
    int a = 0; // counter

    while (getline(myFile, line))
    {
        a++;
        if (a == n)
        {
            cout << line << endl;
            break;
        }
    }

    line.resize(4);

    cout << line << endl;

    int num = stoi(line);

    cout << "num " << num << endl;
}

void resizeDemo(string str)
{

    // Resizes str to a string with
    // 5 initial characters only
    str.resize(5);
    cout << "Using resize : ";
    cout << str;
}

void lastLineReadText()
{
    string filename = ".././data/Patients_list.csv";
    ifstream fin;
    fin.open(filename);
    if (fin.is_open())
    {
        fin.seekg(-1, ios_base::end); // go to one spot before the EOF

        bool keepLooping = true;
        while (keepLooping)
        {
            char ch;
            fin.get(ch); // Get current byte's data

            if ((int)fin.tellg() <= 1)
            {                        // If the data was at or before the 0th byte
                fin.seekg(0);        // The first line is the last line
                keepLooping = false; // So stop there
            }
            else if (ch == '\n')
            {                        // If the data was a newline
                keepLooping = false; // Stop at the current position.
            }
            else
            {                                 // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2, ios_base::cur); // Move to the front of that data, then to the front of the data before it
            }
        }

        string lastLine;
        getline(fin, lastLine);                 // Read the current line
        cout << "Result: " << lastLine << '\n'; // Display it

        fin.close();
    }
}

string lastlineReadCSV()
{
    string line, lastLine;
    ifstream infile;
    string filename = ".././data/Doctors_list.csv";
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

int power(int n, int exp)
{
    int res = 1;
    while (exp)
    {
        if (exp & 1)
            res *= n, exp--;
        else
            n *= n, exp >>= 1;
    }
    return res;
}
int strToNum(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += ((s[s.size() - 1 - i] - '0') * power(10, i));
    return res;
}

string getID()
{
    string line;
    ifstream infile;
    string filename = "./test.csv";
    infile.open(filename);

    if (infile.is_open())
    {
        getline(infile, line, ',');
        // cout << "The last line : " << line << '\n';
    }
    // int id = stoi(line);
    string i = Last_str_word(line);
    return i;
}

string Last_str_word(const string &text)
{
    int i = text.length() - 1;

    if (isspace(text[i]) && i == ',')
        while (isspace(text[i]))
            i--;

    while (i != 0 && !isspace(text[i]))
        --i;

    string lastword = text.substr(i + 1);
    return lastword;
}

void DocterDelete()
{
    ifstream fin;
    ofstream fout;

    fin.open("./test.csv", ios::in);
    fout.open("./example.csv", ios::out);
    if (fin.fail())
    {
        cout << "File open Failed" << endl;
    }

    string line, first_word, match;
    vector<string> lines;
    match = "1101";

    // Read the lines from the file into a vector
    while (getline(fin, line))
    {
        first_word = line.substr(0, line.find(","));
        if (first_word != match)
        {
            lines.push_back(line);
        }
    }
    fin.close();
    remove("./test.csv");

    for (const auto &l : lines)
    {
        fout << l << endl;
    }

    rename("./example.csv", "./test.csv");
    fout.close();
}
