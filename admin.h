#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>
using namespace std;
#include"registereduser.cpp"
int totalflights=20;

class admin:public registereduser{
public:
int id;
string getusername();
string getpassword();
void setusername(string);
void setpassword(string);
void setid(int);
void getpersonaldetails();
void changefs(flight*,airport*);
void changeflightroute(flight*);
void restrictflight(flight*);
bool inrange(int,int,int);
void findclash(flight*);
};

#endif
