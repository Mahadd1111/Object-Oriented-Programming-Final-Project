#ifndef FLIGHT_H
#define FLIGHT_H

#include<iostream>
using namespace std;
//#include"passenger.cpp"
#include"specialflight.cpp"
#include"time.h"
#include"airport.cpp"
#include<string>

class flight{
public:
int currentseat;
string start;
string end;
int distance;
specialflight* sf;
bool local;
int id;
times departuretime;
times arrivaltime;
airport ap;
bool seats[60];
double cost;

public:
void setflight(bool,int,string,string,airport,int);
void setdeparturearrival(int,int,double);
string getstart();
string getend();
double getcost();
string getlocal();
string getdeparturetime();
string getarrivaltime();
string getairport();
int getid();
int getarrivalhour();
airport getap();
int getcurrentseat();
void updateseats();
void initialiseseats();
int getdeparturehour();
};

#endif
