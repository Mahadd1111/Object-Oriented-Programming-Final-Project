#ifndef FLIGHT_CPP
#define FLIGHT_CPP


#include<iostream>
using namespace std;

#include"flight.h"


void flight::setflight(bool l, int i,string s,string e,airport a,int d){
local=l;
id=i;
ap=a;
distance=d;
start=s;
end=e;
}

void flight::setdeparturearrival(int num1,int num2,double hrs){
departuretime.hour=num1; //departure time being set
departuretime.minute=num2;
arrivaltime.hour=num1;
arrivaltime.minute=num2;

        for(int i=0;i<(hrs-((int)hrs))*60;i++){ //this adds minutes parts of arrival time
                if(arrivaltime.minute>=60){
                arrivaltime.hour++;
                        if(arrivaltime.hour==24){
                        arrivaltime.hour=0;
                        }
                arrivaltime.minute=0;
                }
                else{
                arrivaltime.minute++;
                }
        }

        for(int i=0;i<(int)hrs;i++){ //this adds the hours part of arrivaltime
                if(arrivaltime.hour>=24){
                arrivaltime.hour=0;
                }
                else{
                arrivaltime.hour++;
                }
        }

        if(local==false){
        cost=0.15*distance;
        }
        else{
        cost=0.10*distance;
        }
}


string flight::getstart(){
return start;
}

string flight::getend(){
return end;
}

double flight::getcost(){
return cost;
}

string flight::getlocal(){
        if(local==0){
        return "Foreign";
        }
return "Local";
}


string flight::getdeparturetime(){
return departuretime.displaytime();
}

string flight::getarrivaltime(){
return arrivaltime.displaytime();
}

string flight::getairport(){
return ap.getairportinfo();
}

int flight::getid(){
return id;
}

int flight::getarrivalhour(){
return arrivaltime.hour;
}

int flight::getdeparturehour(){
return departuretime.hour;
}

airport flight::getap(){
return ap;
}

void flight::initialiseseats(){
currentseat=0; //first available seat for this flight is seat 0
for(int i=0;i<60;i++){
seats[i]=0; //meaning seat not in use
}
}

void flight::updateseats(){
seats[currentseat]=true;
currentseat++;
}

int flight::getcurrentseat(){
return currentseat;
}


#endif


