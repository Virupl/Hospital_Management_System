#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "./../include/appointment.hh"
#include "./../include/Docters.hh"
#include "./../include/Patients.hh"
#include "./../include/Admin.hh"
#include "./../include/hospital.hh"
#include "./../include/Time.hh"

Time tl;
string date = tl.get_date();

void appointment::book()
{
    cout << "\n\nIs the patient already registered (Y : Yes || N : No)?\n";
    char ans;
    cin >> ans;
    while (ans != 'Y' && ans != 'N')
    {
        cout << "Y or N?\n";
        cin >> ans;
    }
    if (ans == 'N' || ans == 'n')
    {
        cout << "Register the patient:\n";
        patient p;
        p.input();
    }
    else
    {
        cout << "Search for the required patient:\n\n";
        ans = 'Y';
        if (ans == 'Y')
        {
            cout << "Enter the patient's id: ";
            cin >> Pid;

            // PFirst, PSecond, PThird, Pline;

            ifstream finP;
            finP.open("./data/Patients_list.csv", ios::in);
            // Read the lines from the file into a vector
            while (getline(finP, Pline))
            {
                int pos = Pline.find(",");
                int pos1 = Pline.find(",");
                int pos2 = Pline.find(",", pos1 + 1);
                PFirst = Pline.substr(0, Pline.find(","));
                PSecond = Pline.substr(pos + 1, Pline.find(",", pos + 1) - pos - 1);
                PThird = Pline.substr(pos2 + 1, Pline.find(",", pos2 + 1) - pos2 - 1);
                if (PFirst == Pid)
                {
                    cout << Pline << endl;
                    break;
                }
                else if (PFirst != Pid)
                {
                    // cout << "Patient id is not valid! Try again." << endl;
                    // sleep(1);
                    // Admin ad;
                    // ad.AdminAdd();
                }
            }
            finP.close();
        }
        cout << "\n\nNow, search for the required doctor:\n";
        ans = 'Y';
        if (ans == 'Y')
        {
            cout << "Enter the doctor id: ";
            cin >> Did;

            // DFirst, DSecond, DThird, Dline;

            ifstream finD;
            finD.open("./data/Doctors_list.csv", ios::in);
            while (getline(finD, Dline))
            {
                int pos = Dline.find(",");
                int pos1 = Dline.find(",");
                int pos2 = Dline.find(",", pos1 + 1);
                DFirst = Dline.substr(0, Dline.find(","));
                DSecond = Dline.substr(pos + 1, Dline.find(",", pos + 1) - pos - 1);
                DThird = Dline.substr(pos2 + 1, Dline.find(",", pos2 + 1) - pos2 - 1);
                if (DFirst == Did)
                {
                    cout << Dline << endl;
                    break;
                }
                else if (DFirst != Did)
                {
                    // cout << "Doctor id is not valid! Try again." << endl;
                    // sleep(1);
                    // Admin ad;
                    // ad.AdminAdd();
                }
            }
            finD.close();
        }
    }
    cout << "\nAppointment of patient " + PSecond + " " + PThird + " with doctor "
         << DSecond << " " << DThird << " booked successfully!\n";

    printDetails();
}

void appointment::printDetails()
{
    cout << "\n\tAppointment Details:\n\t\tID                 : " << id << "\n"
         << "\t\tPatient's Name     : " + PSecond + " " + PThird + "(ID = " << Pid << ")\n"
         << "\t\tDoctor's Name      : " + DSecond + " " + DThird + "(ID = " << Did << ")\n"
         << "\t\tTime (24 Hr format): " << hh << ":00 Hrs to " << hh + 1 << ":00 Hrs\n\n";

    fillData();
    return;
}

void appointment::fillData()
{
    ofstream fout;
    fout.open("./data/Appointments.csv", ios::app);

    fout << "appointmentId,date(DDMMYYYY),doctorId,patientId,startTime(in 24-hr format)" << endl;
    fout << id << "," << date << "," << Did << "," << Pid << "," << hh << ":00 Hrs to " << hh + 1 << ":00 Hrs" << endl;

    fout.close();
}

// void appointment::getappointment()
// {
//     cout << "\nEnter appointment ID:\n";
//     cin >> id;
//     if (hospital::appointmentsList.find(id) == hospital::appointmentsList.end())
//     {
//         cout << "\nInvalid appointment ID!\n";
//         id = -1;
//         return;
//     }
//     *this = hospital::appointmentsList[id];
//     return;
// }

void appointment::showallAp()
{
    ifstream fin;
    fin.open("./data/Appointments.csv", ios::in);

    if (fin.fail())
    {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
}
