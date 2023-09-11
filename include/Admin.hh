#ifndef ADMIN
#define ADMIN

using namespace std;
// Admin
class Admin
{
private:
    char name[50], DOB[20], Mobile_no[15], Address[100], ID[20], Password[20];

public:
    void AdminAdd();
    void Login_Admin();
    void input();
};

#endif