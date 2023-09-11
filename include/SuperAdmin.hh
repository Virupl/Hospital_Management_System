#ifndef SUPERADMIN
#define SUPERADMIN

using namespace std;
class SupAdmin
{
public:
    void Login_Sup_Admin();
    void SuperAdd();
};

// Super Admin
class Sup_Admin
{
private:
    char name[50], DOB[20], Mobile_no[15], Address[100], ID[20], Password[20];

public:
    void input();
};

#endif