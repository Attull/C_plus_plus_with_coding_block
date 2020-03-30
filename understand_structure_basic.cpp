#include <iostream>
using namespace std;

struct emp
{
    int empno;
    double salary;
};

void read(emp &e)
{
    cout<<"enter employee number ";
    cin>>e.empno;
    cout<<endl<<"enter salary ";
    cin>>e.salary;
}
void show(emp &e)
{
    cout<<endl;
    cout<<"employee info \n";
    cout<<"number "<<e.empno;
    cout<<endl;
    cout<<"salary "<<e.salary;
}
int main() {

    emp e1;
    read(e1);
    show(e1);
	return 0;
}


