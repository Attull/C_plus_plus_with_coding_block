 #include<iostream>
 #
 using namespace std;

 void readmatrix(int a[][10],int R,int C)
 {
     for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            cin>>a[i][j];
 }

 void largest_sum(int arr[][10],int R,int C)
 {
     int maxx=0;
     int temp[10]={0};

     //storing sum row wise
     for(int i=0;i<R;++i)
     {
         int sum=0;
         for(int j=0;j<C;++j)
         {
             sum+=arr[i][j];
         }
         temp[i]=sum;
     }

    maxx=temp[0];
    int pos=0;
    for(int k=0;k<R;++k)
    {
        if(temp[k]<temp[k+1])
         {
            maxx=temp[k+1];
            pos=k+1;
        }
    }
    cout<<endl<<"Maximum sum is along row "<<pos<<" is "<<maxx;
 }

 int main()
 {
    int R,C;
    int a[10][10];

    cout<<"enter no. of row & column \n";
    cin>>R>>C;

    readmatrix(a,R,C);           //read the matrix

    largest_sum(a,R,C);

    return 0;
 }
