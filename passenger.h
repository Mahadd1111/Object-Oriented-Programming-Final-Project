#ifndef PASSENGER_H
#define PASSENGER_H

class flight;
#include<iostream>
using namespace std;
#include"registereduser.cpp"
#include"passport.cpp"
#include"flight.cpp"
#include"booking.cpp"

class passenger:public registereduser{
int id;
unsigned long long cnic;
int points;
passport pp;
booking bk;
accountdetails ac;

public:
string getusername();
string getpassword();
void setusername(string);
void setpassword(string);
void setpassengerinfo(int,unsigned long long);
int getid();
unsigned long long getcnic();
void setbk(flight&);
booking& getbk();
void setaccountdetails(string [],int);
void setaccountdetails(string,int );
void getpassengerdetails();
void booknewflight(flight*);
void viewcurrentbooking();
void calculatediscount();
void resetusernamepassword();
//visitedcountry();
//updatedetails();
//cancelbooking();

};

#endif
