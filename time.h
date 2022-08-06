#include<iostream>
using namespace std;


class times{
public:
int hour;
int minute;

void settime(int h,int m){
hour=h;
minute=m;
}

string displaytime(){
return to_string(hour)+":"+to_string(minute);
}
};                                                                                                                                         
