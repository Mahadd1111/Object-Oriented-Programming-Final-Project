#ifndef BOOKING_H
#define BOOKING_H

#include<iostream>
using namespace std;
class flight;
#include"airport.cpp"
#include"payment.cpp"
#include"flight.cpp"

class booking{
public:
int bookingid;
flight f;
int seat;
double bookingcost;
payment p;

public:
void setbooking(flight,int);
void setseat(int);
void setpayment();
double gettax();
//void setflight(flight);
//getbooking();
//getdiscount();
//overload+();


};

#endif
