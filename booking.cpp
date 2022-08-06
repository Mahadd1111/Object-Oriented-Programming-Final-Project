#include<iostream>
using namespace std;

#include"booking.h"

void booking::setbooking(flight f1,int x){
f=f1;
bookingid=x+400;
bookingcost=f.cost;
}

void booking::setseat(int n){
seat=n;
}

void booking::setpayment(){
double tax;
        if(f.local==1){
        p.ticketprice=bookingcost*1.05;
        }
        else{
        p.ticketprice=bookingcost*1.10;
        }

}

double booking::gettax(){
return p.ticketprice-bookingcost;
}





