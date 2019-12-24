#include <iostream>
using namespace std;
int main() {

    int a[2][3]={{1,2,3},{2,3,4}};
    char b[][2]={{'A','B'},{'C','D'}};
    char bb[][4]={{'a','b','c','\0'},{'d','e','\0','g'}};

    char c[10][100]={"atul","aman","ajay"};

    for(int i=0;i<2;++i)
    {    for(int j=0;j<3;++j)
            cout<<a[i][j]<<"\t";

        cout<<endl;
    }

    cout<<bb[0][0]<<endl;
    cout<<b[0]<<endl;                      //b[0] represent starting address and it print all address element after b[0]
    cout<<bb[1];                           //cout run till it find the null character

   //here each row represent the string
    cout<<c[0]<<endl;                      //print entire first row i.e "atul"
    cout<<c[1]<<endl;                      //print entire second row
    cout<<c[2]<<endl;

    cin>>c[3];                            //take input for forth row but no space is allowed
    cin.getline(c[4],100);                //take input for fifth row upto 100 character and space is allowed

    cout<<c[3]<<endl;
    cout<<c[4]<<endl;
    }
