#include<iostream>
using namespace std;

#include"admin.h"


string admin::getusername(){
return uname;
}

string admin::getpassword(){
return pword;
}

void admin::setusername(string u){
uname=u;
}

void admin::setpassword(string p){
pword=p;
}

void admin::setid(int i){
id=i;
}

//Displays details
void admin::getpersonaldetails(){
cout<<"______________________________DISPLAYING ADMIN DETAILS________________________________"<<endl;
cout<<"Username is: "<<uname<<endl;
cout<<"Password is: "<<pword<<endl;
cout<<"Admin ID is: "<<id<<endl;
cout<<"______________________________________________________________________________________"<<endl;
}

//make changes in flight schedule
void admin::changefs(flight* f,airport* a){
cout<<"_____________________________CHANGING FLIGHT SCHEDULE__________________________________"<<endl;
cout<<"Would you like to : 1- Remove a flight, or 2 - Add new flight"<<endl;
int choice,del;
cin>>choice;
        if(choice==1){
        int count=0;
                cout<<"Enter flight ID to be deleted: ";
                cin>>del;
                cout<<endl;
                        for(int i=0;i<totalflights;i++){
                                if(f[i].id==del){
                                cout<<"Flight "<<f[i].id<<" found"<<endl;
                                        for(int j=i; j<(totalflights-1); j++){          
                                        f[j]=f[j+1];
                                        }
                                count++;
                                break; 
                                }
                        }
                if(count==0){
                cout<<"Flight not found"<<endl;
                }
                else{
                cout<<"Flight deleted"<<endl;
                totalflights--;
                }
        }
        else if(choice==2){
       /* del=totalflights-1;
                        for(int i=0;i<totalflights;i++){
                                if(i==del){
                                        for(int j=i; j<(totalflights-1); j++){          
                                        f[j]=f[j+1];
                                        }
                                break; 
                                }
                        }
        string takeoff;
        string landing;
        int n4;
        cout<<"Enter Takeoff location: ";
        cin>>takeoff;
        cout<<"\nEnter Landing location: ";
        cin>>landing;
        cout<<endl;
        string s[5]={"Islamabad","Karachi","Lahore","Quetta","Peshawar"};
                for(int i=0;i<5;i++){
                        if(takeoff==s[i]){
                        n4=(i*2) + rand()%2;
                        }
                }
        srand(20);
        int n1=rand()%2;
        int n2=(rand()%1000)+10000;
        f[totalflights-1].setflight(n1,20+totalflights-1,takeoff,landing,a[n4],n2);
        int n5=rand()%24;
        int n6=rand()%49 + 10;
        double n7=rand()%10;
        f[totalflights-1].setdeparturearrival(n5,n6,n7);
        f[totalflights-1].initialiseseats();*/
        cout<<"This option is currently unavailable"<<endl;
        }
        else{
        cout<<"ERROR::Invalid input"<<endl;
        }
}

//change destination of a flight
void admin::changeflightroute(flight* f){
int id;
string dest;
int count=0;
cout<<"_____________________________________CHANGING FLIGHT ROUTE__________________________________"<<endl;
cout<<"Enter ID of flight which route you would like to change: ";
cin>>id;
cout<<endl;
        for(int i=0;i<totalflights;i++){
                if(id==f[i].id){
                        cout<<"Enter New destination for flight: ";
                        cin>>dest;
                        cout<<endl;
                        f[i].end=dest;
                        count++;
                }
        }
        if(count==0){
        cout<<"Flight not found"<<endl;
        }
        else{
        cout<<"Flight destination successfully updated"<<endl;
        }
cout<<"___________________________________________________________________________________________"<<endl;
}

//Dissallow more passengers to this flight
void admin::restrictflight(flight*f){
int id;
int count=0;
cout<<"_____________________________________RESTRICTING FLIGHT__________________________________"<<endl;
cout<<"Enter ID of flight which route you would like to restrict due to Covid-19 restrictions: ";
cin>>id;
cout<<endl;
        for(int i=0;i<totalflights;i++){
                if(id==f[i].id){
                cout<<"Restricting Flight "<<f[i].id<<" ...."<<endl;
                f[i].currentseat=59;
                count++;
                }
        }
        if(count==0){
        cout<<"Flight not found"<<endl;
        }
        else{
        cout<<"Flight successfully restricted"<<endl;
        }
cout<<"___________________________________________________________________________________________"<<endl;
}

bool admin::inrange(int low,int high,int x){
bool flag;
        if(x>=low and x<=high){
        flag=true;
        }
        else{
        flag=false;
        }
return flag;
}

//finds and displays all clashing flights
void admin::findclash(flight* f){
bool overlap=false;
cout<<"___________________________________FINDING CLASHES__________________________________________"<<endl;
cout<<"Looking for clashes...."<<endl;
        for(int i=0;i<totalflights;i++){
                for(int j=0;j<totalflights;j++){
                        if((inrange(f[j].getdeparturehour()-1,f[j].getdeparturehour()+1,f[i].getdeparturehour())==1) and f[i].id!=f[j].id and f[i].getairport()==f[j].getairport()){
                        cout<<"Clash found between flight "<<f[i].id<<" and "<<f[j].id<<" at Airport: "<<f[i].getairport()<<endl;
                        overlap=true;
                        }
                }
        }
        if(overlap==false){
        cout<<"No overlap found"<<endl;
        }
}


