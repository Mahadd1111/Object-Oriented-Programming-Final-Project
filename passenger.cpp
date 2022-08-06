#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string>
using namespace std;

#include"passenger.h"

string passenger::getusername(){
return uname;
}

string passenger::getpassword(){
return pword;
}

void passenger::setusername(string u){
uname=u;
}

void passenger::setpassword(string p){
pword=p;
}

void passenger::setpassengerinfo(int i,unsigned long long c){
id=i;
cnic=c;
srand(i);
int num=rand()%100;
points=num;
}

int passenger::getid(){
return id;
}

unsigned long long passenger::getcnic(){
return cnic;
}

booking& passenger::getbk(){ 
return bk;
}

void passenger::setaccountdetails(string pm[],int n){
ac.accountid=10+n;
srand(n);
int n2=rand()%5;
ac.pmethod=pm[n2];
int n3=rand()%2;
pp.local=n3;
srand(n+12);
int n4=rand()%2;
pp.visa=n4;
}

void passenger::setaccountdetails(string pm,int n){
bk.bookingid=0;
ac.accountid=10+n;
srand(n);
ac.pmethod=pm;
int n3=rand()%2;
pp.local=n3;
srand(n+12);
int n4=rand()%2;
pp.visa=n4;
}

void passenger::getpassengerdetails(){
cout<<"_____________________________________________________________________________________"<<endl;
cout<<"PASSENGER DETAILS: "<<endl;
cout<<"Passenger ID is: "<<id<<endl;
cout<<"Passenger Username is: "<<uname<<endl;
cout<<"Passenger Password is: "<<pword<<endl;
cout<<"Passenger CNIC is: "<<cnic<<endl;
cout<<"Passenger NPAFS GOLD points are: "<<points<<endl;
        if(pp.local==1){
        cout<<"Passenger Passport is Local"<<endl;
        }
        else{ 
        cout<<"Passenger Passport is Foreign"<<endl;
        }
        if(pp.visa==1){
        cout<<"Passenger Visa is Valid"<<endl;
        }
        else{ 
        cout<<"Passenger Visa is Expired"<<endl;
        }   
}

void passenger::booknewflight(flight* f){
cout<<"____________________________________________________________________________________________"<<endl;
string city1;
string city2;
        if(pp.visa==0){
        cout<<"VISA is Expired, Please Renew Visa to Book a flight!"<<endl;
        }
        else{
        cout<<"Enter City of Departure: ";
        cin>>city1;
        cout<<"\nEnter City of Arrival: ";
        cin>>city2;
                for(int i=0;i<20;i++){
                        if(f[i].start == city1 and f[i].end==city2){
                                if(f[i].getcurrentseat()!=59){
                                int num4=f[i].getcurrentseat();
                                bk.setbooking(f[i],i+id);
                                f[i].updateseats(); //this passenger has occupied a seat
                                bk.setseat(num4);
                                bk.setpayment();
                                points+=15;
                                }
                                else{
                                cout<<"There are no more remaining seats on this flight"<<endl;
                                }
                        }
                }
        }
cout<<"________________________________________________________________________________________________"<<endl;
}

void passenger::viewcurrentbooking(){
        if(bk.bookingid==0){
        cout<<"NO Current Booking for your account"<<endl;
        }
        else{
        cout<<"________________________________________________________________________________________________"<<endl;
        cout<<"DETAILS FOR CURRENT BOOKING SHOWN BELOW: "<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"Booking ID is: "<<bk.bookingid<<endl;
        cout<<"Flight's City of Departure is: "<<bk.f.start<<endl;
        cout<<"Flight's City of Arrival is: "<<bk.f.end<<endl;
        cout<<"Flight's Departure time is: "<<bk.f.getdeparturetime()<<endl;
        cout<<"Flight's Arrival time is: "<<bk.f.getarrivaltime()<<endl;
        cout<<"Booking cost is: $"<<fixed<<setprecision(2)<<bk.p.ticketprice<<endl;
        cout<<"TAX on booking is: $"<<fixed<<setprecision(2)<<bk.gettax()<<endl;
        cout<<"Method of Payment is: "<<ac.pmethod<<endl;
        cout<<"Booking was done from Account with ID: "<<ac.accountid<<endl;
        cout<<"--------------------------------------------------"<<endl;
        }
cout<<"________________________________________________________________________________________________"<<endl;
}

void passenger::calculatediscount(){
cout<<"________________________________________________________________________________________________"<<endl;
        if(points>=50){
        cout<<"CONGRATULATIONS! YOU ARE ELIGIBLE FOR 10% DISCOUNT"<<endl;
        cout<<"Your NPAFS GOLD points are: "<<points<<endl;
        bk.p.ticketprice=bk.p.ticketprice-(bk.p.ticketprice/5);
        cout<<"NEW ticket price is: $"<<fixed<<setprecision(2)<<bk.p.ticketprice<<endl;
        }
        else{
        cout<<"Unfortunately you are not eligible for discount, You must have atleast 50 NPAFS GOLD points"<<endl;
        cout<<"Your NPAFS GOLD points are: "<<points<<endl;
        }
}

void passenger::resetusernamepassword(){
string newusername,newpassword;
cout<<"Enter New username: ";
cin>>newusername;
bool uppercase=false;
bool specialcharacter=false;
bool number=false;
bool length=false;
        while(uppercase==false or specialcharacter==false or number==false or length==false){
        cout<<"\nEnter New Password: ";
        cin>>newpassword;
        cout<<endl;
        int size=newpassword.length();
                if(size>=8){
                length = true;
                }
                for(int i=0;i<size;i++){
                        if(newpassword[i]>=65 and newpassword[i]<=90){
                        uppercase=true;
                        }
                        if((newpassword[i]>=33 and newpassword[i]<=38) or newpassword[i]==64){
                        specialcharacter=true;
                        }
                        if(newpassword[i]>=48 and newpassword[i]<=57){
                        number=true;
                        }
                }
                if(uppercase==false or specialcharacter==false or number==false or length==false){
                cout<<"INVALID INPUT:: PASSWORD must have atleast 1 Upper case, 1 Special Character, 1 Number, and have 8 or more characters"<<endl;
                }
        }       
uname=newusername;
pword=newpassword;
}



