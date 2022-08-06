#ifndef NPAFS_H
#define NPAFS_H

#include<iostream>
using namespace std;
#include"passenger.cpp"  
#include"admin.cpp"

class npafs{
admin* ad=new admin[10];
passenger* ps=new passenger[10];
passenger pass[300];
flight* fl=new flight[20];
airport *aport=new airport[10];

public:
void showflights();
void setairports();
void setflights(string*,string*,int*,double*);
void setadminslogin();
void setpassengerslogin();
void setpassengersinfo(string []);
void setrandompassengersinfo(string []);
void menu();
void aboutinfo();
void userlogin();
void setadminsinfo();
void adminlogin();
void accesspassenger(passenger&);
void newuser();
void accessadmin(admin&);
//verifyfinancialdetails();
};


#endif
