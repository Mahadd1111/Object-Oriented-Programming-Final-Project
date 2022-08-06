#include<iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
#include"npafs.cpp"

int main(){
//_________________________________________________________SAVING DATA__________________________________________________________
//lets save some cities, their distances, and their flight times
string l1cities[5]={"Islamabad","Karachi","Lahore","Quetta","Peshawar"};
string f1cities[5]={"New York","Barcalona","Rio","Sydney","Istanbul"};
int d1cities[5]={12000,6500,14000,9000,3000};
double t1cities[5]={13.54,7.16,15.1,10.12,3.55};
string pmethods[5]={"VISA","MASTER CARD","CASH","JAZZ CASH","PAYPAL"};

// NPAFS OBJECT
npafs controller;

//lets create some airports!
controller.setairports();

//Lets save data of some 15 international flights and 5 local flights happening right now
controller.setflights(l1cities,f1cities,d1cities,t1cities);

//Now lets take data from txt files and save them as admins and passengers.
controller.setadminslogin();
controller.setpassengerslogin();

//Setting information for passsengers we will use and random passengers that are occupying flights
controller.setpassengersinfo(pmethods);
controller.setrandompassengersinfo(pmethods);

//Setting admins information
controller.setadminsinfo();

//showing menu and running program
controller.menu();
return 0;
}



