 #include<iostream>
using namespace std;

 void readmatrix(int a[][10],int R,int C)
 {
     for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            cin>>a[i][j];
 }

 void staircasesearch(int a[][10],int R,int C,int key)
 {
     int i=0;                                                  //first row
     int j=C-1;                                                //last column

     while(i>=0 && j<C)
     {
         if(a[i][j]==key)                                       //if element is found then print position
          {
            cout<<"element is found at "<<i<<","<<j;
            return ;
          }
         else if(a[i][j]>key)                                   //if search element is less than current element
            --j;
         else                                                   //if search element is greater than current element
            ++i;
     }
     cout<<"element is not found ";
 }

 int main()
 {
    int R,C;
    int a[10][10];

    cout<<"enter no. of row & column \n";
    cin>>R>>C;

    readmatrix(a,R,C);           //read the matrix

    int key;
    cout<<"Enter the element to search ";
    cin>>key;

    staircasesearch(a,R,C,key);

    return 0;
 }
