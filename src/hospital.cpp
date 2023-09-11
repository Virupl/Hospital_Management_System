#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#include "./../include/Docters.hh"
#include "./../include/Patients.hh"
#include "./../include/Nurses.hh"
#include "./../include/Driver.hh"
#include "./../include/Ambulance.hh"
#include "./../include/appointment.hh"
#include "./../include/hospital.hh"

map<int, Doctor> hospital::doctorsList;
map<int, patient> hospital::patientList;
map<int, Nurses> hospital::nursesList;
map<int, Drivers> hospital::driverList;
map<int, Ambulance> hospital::ambulanceList;
map<int, appointment> hospital::appointmentsList;

void hospital::printDoctors()
{
    for (auto i : doctorsList)
        i.second.printDetails(), cout << "\n";
    return;
}

void hospital::printAppointments()
{
    for (auto i : appointmentsList)
        i.second.printDetails(), cout << "\n";
    return;
}

int main()
{
    hospital h;
    h.printDoctors();

    return 0;
}