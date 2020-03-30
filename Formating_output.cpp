#include<iostream>
#include<iomanip>                                           //used for setw and setprecision
using namespace std;
int main()
{
    double radius=7.5,area,perimeter;

    perimeter=2*radius*radius;
    area=3.14*radius*radius;

    cout<<"AREA is \t";
    cout<<setw(20)<<radius<<endl;                            //set given space before output

    cout<<setprecision(6)<<area<<endl;                       //set total number of digit to be displayed

    cout.setf(ios::fixed);                                   //set the number of decimal places to be displayed
    cout<<setprecision(4)<<123.456789<<endl;


    return 0;

}


