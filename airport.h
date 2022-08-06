#ifndef AIRPORT_H
#define AIRPORT_H

#include<iostream>
#include<string>
using namespace std;

class airport{
public:
int id;
string city;
string direction;
bool planeslocal[5];
bool planesinternational[5];

void setairport(int,string,string);
int getid();
string getcity();
string getdirection();
string getairportinfo();
};

#endif
