#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<unistd.h>
#include"npafs.h"


//showing flights
void npafs::showflights(){
cout<<"----------------------------------------DISPLAYING FLIGHTS----------------------------------------------"<<endl;
cout<<setw(4)<<left<<"ID"<<setw(12)<<left<<"FROM"<<setw(12)<<left<<"TO"<<setw(10)<<left<<"TYPE"<<setw(10)<<left<<"DEPARTURE"<<setw(10)<<left<<"ARRIVAL"<<setw(20)<<left<<"AIRPORT"<<setw(10)<<left<<"COST($)"<<endl;
        for(int i=0;i<totalflights;i++){       
                        cout<<setw(4)<<left<<fl[i].getid()<<setw(12)<<left<<fl[i].getstart()<<setw(12)<<left<<fl[i].getend()<<setw(10)<<left<<fl[i].getlocal()<<setw(10)<<left<<fl[i].getdeparturetime()<<setw(10)<<left<<fl[i].getarrivaltime()<<setw(20)<<left<<fl[i].getairport()<<setw(10)<<left<<fixed<<setprecision(2)<<fl[i].getcost()<<endl;
        }
}

//setting airports
void npafs::setairports(){
        aport[0].setairport(10,"Islamabad","North");
        aport[1].setairport(11,"Islamabad","South");
        aport[2].setairport(12,"Karachi","North");
        aport[3].setairport(13,"Karachi","South");
        aport[4].setairport(14,"Lahore","North");
        aport[5].setairport(15,"Lahore","South");
        aport[6].setairport(16,"Quetta","North");
        aport[7].setairport(17,"Quetta","South");
        aport[8].setairport(18,"Peshawar","North");
        aport[9].setairport(19,"Peshawar","South");
}


//setting original flights
void npafs::setflights(string* lcities,string* fcities,int* dcities,double* tcities){
int n1,n2,n3,n4,n5,n6;
        for(int i=0;i<15;i++){ //international flights
        srand(i);
        n1=0;
        n2=rand()%5;
        srand(i*3);
        n3=rand()%5;
        n4=(n2*2) + rand()%2;
        fl[i].setflight(n1,20+i,lcities[n2],fcities[n3],aport[n4],dcities[n3]);
        n5=rand()%24;
        n6=rand()%49 + 10;
        fl[i].setdeparturearrival(n5,n6,tcities[n3]);
        fl[i].initialiseseats();
        }

        for(int i=15;i<20;i++){ //local flights
        srand(i);
        n1=1;
        n2=rand()%5;
        srand(i*3);
        n3=rand()%5;
                while(n3==n2){
                srand(i+30);
                n3=rand()%5;
                }
        n4=n2*2 + rand()%2;
        fl[i].setflight(n1,20+i,lcities[n2],lcities[n3],aport[n4],rand()%1500);
        n5=rand()%24;
        n6=rand()%50 + 10;
        fl[i].setdeparturearrival(n5,n6,tcities[n3]);
        fl[i].initialiseseats();
        }
}

void npafs::setadminslogin(){
        //Now lets take data from txt files and save them as admins and passengers.
        string str,str1,str2;
        ifstream myfile;
        myfile.open("admin.txt");
                if(myfile.good()){
                        for(int i=0;i<10;i++){
                        getline(myfile,str);
                        myfile>>str1;
                        myfile>>str2;
                        ad[i].setusername(str1);
                        ad[i].setpassword(str2);
                        }
                }
}

void npafs::setpassengerslogin(){
        string str,str1,str2;
        ifstream myfile2;
        myfile2.open("passenger.txt");
                if(myfile2.good()){
                        for(int i=0;i<10;i++){
                        getline(myfile2,str);
                        myfile2>>str1;
                        myfile2>>str2;
                        ps[i].setusername(str1);
                        ps[i].setpassword(str2);
                        }
                }
}

//Setting the passengers with usernames and logins (the one we will show and extract information for) 
void npafs::setpassengersinfo(string pm[]){
        for(int i=0;i<10;i++){
        int num1=300+i;
        srand(i+6);
        generate2:
        unsigned long long num2=(rand()%8999999999999) + 1000000000000;
                for(int j=0;j<10;j++){ //making sure no repetitive cnic numbers in the previous passengers made
                        if(num2==ps[j].getcnic()){
                        srand((i*j)+50);
                        goto generate2;
                        }
                }
        ps[i].setpassengerinfo(num1,num2);
        srand(i+12);
        int num3=rand()%20;
        int num4=fl[num3].getcurrentseat();
        ps[i].getbk().setbooking(fl[num3],i+100);
        fl[num3].updateseats(); //this passenger has occupied a seat
        ps[i].getbk().setseat(num4);
        ps[i].setaccountdetails(pm,i);
        ps[i].getbk().setpayment();
        }
}

void npafs::setrandompassengersinfo(string pm[]){
//Time to set random passengers to fill seats
        for(int i=0;i<300;i++){
        int num1=200+i;
        srand(i);
        generate:
        int num2=(rand()%8999999999999) + 1000000000000;
                for(int j=0;j<300;j++){ //making sure no repetitive cnic numbers in these passengers
                        if(num2==pass[j].getcnic()){
                        srand((i*j)+5);
                        goto generate;
                        }
                }
                for(int j=0;j<10;j++){ //making sure no repetitive cnic numbers in the previous passengers made
                        if(num2==ps[j].getcnic()){
                        srand((i*j)+50);
                        goto generate;
                        }
                }
        pass[i].setpassengerinfo(num1,num2);
        srand(i+10);
        int num3=rand()%20;
        int num4=fl[num3].getcurrentseat();
        pass[i].getbk().setbooking(fl[num3],i+200);
        fl[num3].updateseats(); //this passenger has occupied a seat
        pass[i].getbk().setseat(num4);
        }

}

void npafs::setadminsinfo(){
        for(int i=0;i<10;i++){
        int num1=300+i;
        ad[i].setid(num1);
        }
}

//Function that tells user about NPAFS Details
void npafs::aboutinfo(){
cout<<"NPAFS is Pakistan's all new airline spreading across 5 major cities. It is organized and programmed by the great Mahad Ahmed"<<endl;
cout<<"We have over 50 000 daily passengers and conduct over 20 flights daily to over 25 countries"<<endl;

}

//FUNCTIONS AFTER PASSENGER LOGS IN
void npafs::accesspassenger(passenger& p){
cout<<"-------------------------------------WELCOME BACK!----------------------------------"<<endl;
cout<<"1-View Personal Details\n2-Book a flight\n3-View Current Booking\n4-Get Discount on Booking\n5-Reset Username/Password\n6-Back to Menu\n7-Exit Program"<<endl;
int choice;
enter:
cout<<"\nEnter choice of option from above menu: ";
cin>>choice;
cout<<endl<<"--------------------------------------------------------------------------------------------------------\n";

        switch(choice){

        case 1:
        p.getpassengerdetails();
        accesspassenger(p);
        break;

        case 2:
        p.booknewflight(fl);
        accesspassenger(p);
        break;

        case 3:
        p.viewcurrentbooking();
        accesspassenger(p);
        break;

        case 4:
        p.calculatediscount();
        accesspassenger(p);
        break;

        case 5:
        p.resetusernamepassword();
        accesspassenger(p);
        break;

        case 6:
        menu();
        break;
        
        case 7:
        exit(0);
        break;
        }

}



//FUNCTIONS AFTER ADMIN LOGS IN
void npafs::accessadmin(admin& a){
cout<<"-------------------------------------WELCOME BACK!----------------------------------"<<endl;
cout<<"1-View Personal Details\n2-Change flight Schedule\n3-Change flight route\n4-Restrict Passengers for a flight\n5-Find if there is a clash in flights\n6-Back to Menu\n7-Exit Program"<<endl;
int choice;
enter:
cout<<"\nEnter choice of option from above menu: ";
cin>>choice;
cout<<endl<<"--------------------------------------------------------------------------------------------------------\n";

        switch(choice){

        case 1:
        a.getpersonaldetails();
        accessadmin(a);
        break;

        case 2:
        a.changefs(fl,aport);
        accessadmin(a);
        break;

        case 3:
        a.changeflightroute(fl);
        accessadmin(a);
        break;

        case 4:
        a.restrictflight(fl);
        accessadmin(a);
        break;

        case 5:
        a.findclash(fl);
        accessadmin(a);

        case 6:
        menu();
        break;
        
        case 7:
        exit(0);
        break;
        }

}

//LOGGING IN AS USER
void npafs::userlogin(){
string username;
string password;
string savedusername;
string savedpassword;
string str;
cout<<"________________________________________________________________________________________"<<endl;
cout<<"WELCOME TO PASSENGER LOGIN"<<endl;
bool flag1=true;
bool flag2=true;
bool exit=false;
int count=0;
int count2=0;
ifstream file;
ifstream file2;

        while(flag1==true){
        cout<<"Enter Username or enter 'x' to exit (case sensitive): "<<endl;
        cin>>username;
        cout<<endl;
                if(username=="x"){
                 exit=true;
                 break;       
                }
        file.open("passenger.txt");
                        while(!file.eof() and flag1==true){
                        getline(file,str);
                        file>>savedusername;
                        file>>savedpassword;
                                if(savedusername==username){
                                flag1=false;
                                }
                        count++;
                        }
                        if(flag1==true){
                        cout<<"No such username found in database"<<endl;
                        }
        file.close();
        }
        if(exit==true){
        menu();
        }
        //Now entering password and checking if it exists
        while(exit==false and flag2==true){
        password = getpass("Enter Password or enter 'x' to exit ->as a security feature, your password will not show while writing: ");
        cout<<endl;
                if(password=="x"){
                 exit=true;
                 break;       
                }
        file2.open("passenger.txt");
                        while(!file2.eof() and flag2==true){
                        getline(file2,str);
                        file2>>savedusername;
                        file2>>savedpassword;
                                if(savedpassword==password and count==count2+1){
                                flag2=false;
                                }
                                count2++;
                        }
                if(flag2==true){
                cout<<"No such Password found in database"<<endl;
                }
        file2.close();
        }
        if(exit==true){
        menu();
        }
        if(flag1==false and flag2==false){
        cout<<"Login accessed"<<endl;
        accesspassenger(ps[count-1]);
        }
        else{
        cout<<"GOING BACK TO MENU"<<endl;
        menu();
        }
        
}


//LOGGING IN AS ADMIN
void npafs::adminlogin(){
string username;
string password;
string savedusername;
string savedpassword;
string str;
cout<<"________________________________________________________________________________________"<<endl;
cout<<"WELCOME TO ADMIN LOGIN"<<endl;
bool flag1=true;
bool flag2=true;
bool exit=false;
int count=0;
int count2=0;
ifstream file;
ifstream file2;

        while(flag1==true){
        cout<<"Enter Username or enter 'x' to exit (case sensitive): "<<endl;
        cin>>username;
        cout<<endl;
                if(username=="x"){
                 exit=true;
                 break;       
                }
        file.open("admin.txt");
                        while(!file.eof() and flag1==true){
                        getline(file,str);
                        file>>savedusername;
                        file>>savedpassword;
                                if(savedusername==username){
                                flag1=false;
                                }
                        count++;
                        }
                        if(flag1==true){
                        cout<<"No such username found in database"<<endl;
                        }
        file.close();
        }
        if(exit==true){
        menu();
        }
        //Now entering password and checking if it exists
        while(exit==false and flag2==true){
        password = getpass("Enter Password or enter 'x' to exit ->as a security feature, your password will not show while writing: ");
        cout<<endl;
                if(password=="x"){
                 exit=true;
                 break;       
                }
        file2.open("admin.txt");
                        while(!file2.eof() and flag2==true){
                        getline(file2,str);
                        file2>>savedusername;
                        file2>>savedpassword;
                                if(savedpassword==password and count==count2+1){
                                flag2=false;
                                }
                                count2++;
                        }
                if(flag2==true){
                cout<<"No such Password found in database"<<endl;
                }
        file2.close();
        }
        if(exit==true){
        menu();
        }
        if(flag1==false and flag2==false){
        cout<<"Login accessed"<<endl;
        accessadmin(ad[count-1]);
        }
        else{
        cout<<"GOING BACK TO MENU"<<endl;
        menu();
        }
        
}

//Function for new user registration
void npafs::newuser(){
cout<<"________________________________WELCOME TO REGISTRATION____________________________________"<<endl;
cout<<"Select Your category: "<<endl;
cout<<"1-Admin\n2-Passenger"<<endl;
int choice;
cin>>choice;
        if(choice==1){
        //first we make new admin,then get un/pw, append in admin files, then set admin details
                admin newad;
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
                newad.setusername(newusername);
                newad.setpassword(newpassword);
                ofstream file1;
                file1.open("admin.txt",ios::app);
                file1<<newusername+" "+newpassword<<endl;
                file1.close();
                int n1=(rand()%60)+700;
                cout<<"You've been assigned Admin ID: "<<n1<<endl;
                newad.id=n1;
                }
        else if(choice==2){
        //first we make new admin,then get un/pw, append in admin files, then set admin details
                passenger newps;
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
                newps.setusername(newusername);
                newps.setpassword(newpassword);
                ofstream file2;
                file2.open("passenger.txt",ios::app);
                file2<<newusername+" "+newpassword<<endl;
                file2.close();
                int n2=(rand()%60)+900;
                cout<<"You've been assigned Passenger ID: "<<n2<<endl;
                unsigned long long int num2;
                generate:
                cout<<"Enter 13 digit CNIC"<<endl;
                cin>>num2;
                        if(num2<1000000000000 or num2>9999999999999){
                        cout<<"INVALID CNIC NUMBER, INPUT AGAIN"<<endl;
                        goto generate; 
                        }
                        for(int j=0;j<300;j++){ //making sure no repetitive cnic numbers in these passengers
                                if(num2==pass[j].getcnic()){
                                srand((j)+5);
                                goto generate;
                                }
                        }
                        for(int j=0;j<10;j++){ //making sure no repetitive cnic numbers in the previous passengers made
                                if(num2==ps[j].getcnic()){
                                srand((j)+50);
                                goto generate;
                                }
                        }
                string pay;
                newps.setpassengerinfo(n2,num2);
                cout<<"Enter Payment method: from VISA,MASTER CARD,CASH,JAZZ CASH,PAYPAL"<<endl;
                cin.ignore();
                getline(cin,pay);
                int n3=rand()%20;
                newps.setpassengerinfo(n2,num2);
                newps.setaccountdetails(pay,n3);
                }
        else{
                cout<<"ERROR::Invalid Input Entered"<<endl;
        }
menu();        
}


void npafs::menu(){
cout<<"______________________________________WELCOME TO NPAFS______________________________________________________"<<endl;
cout<<"1-View Flights\n2-Login as a user\n3-Register as a new user\n4-Login as an admin\n5-About NPAFS\n6-Exit Program";
int choice;
enter:
cout<<"\nEnter choice of option from above menu: ";
cin>>choice;
cout<<endl<<"--------------------------------------------------------------------------------------------------------\n";

        switch(choice){

        case 1:
        showflights();
        break;

        case 2:
        userlogin();
        break;

        case 3:
        newuser();
        break;

        case 4:
        adminlogin();
        break;

        case 5:
        aboutinfo();
        break;

        case 6:
        exit(0);
        break;

        }
menu();
}

