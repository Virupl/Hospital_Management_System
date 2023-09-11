#ifndef HOSPITAL
#define HOSPITAL

#include <map>

#include "./Docters.hh"
#include "./Patients.hh"
#include "./Nurses.hh"
#include "./Driver.hh"
#include "./Ambulance.hh"
#include "./appointment.hh"

class hospital
{
private:
    static map<int, Doctor> doctorsList;
    static map<int, patient> patientList;
    static map<int, Nurses> nursesList;
    static map<int, Drivers> driverList;
    static map<int, Ambulance> ambulanceList;
    static map<int, appointment> appointmentsList;

public:
    static void printDoctors();
    static void printAppointments();
};

#endif