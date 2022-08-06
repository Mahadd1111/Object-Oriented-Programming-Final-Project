#ifndef REGISTEREDUSER_H
#define REGISTEREDUSER_H

#include<iostream>
using namespace std;
#include"accountdetails.cpp"

class registereduser{
protected: 
string uname;
string pword;
accountdetails* account;
};

#endif
