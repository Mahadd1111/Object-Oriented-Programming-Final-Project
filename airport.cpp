#ifndef AIRPORT_CPP
#define AIRPORT_CPP

#include<iostream>
using namespace std;

#include"airport.h"

void airport::setairport(int i,string c,string d){
id=i;
city=c;
direction=d;
}

int airport::getid(){
return id;
}

string airport::getcity(){
return city;
}

string airport::getdirection(){
return direction;
}

string airport::getairportinfo(){
return direction+" "+city;
}


#endif
