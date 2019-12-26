 #include<iostream>
 using namespace std;

 void readmatrix(int a[][10],int R,int C)
 {
     for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            cin>>a[i][j];
 }

void printmatrix(int a[][10],int R,int C)
 {
     for(int i=0;i<R;++i)
     {
         for(int j=0;j<C;++j)
            cout<<a[i][j]<<" ";

      cout<<endl;
     }
 }

 void waveprint(int a[][10],int R,int C)
 {
     for(int j=0;j<C;++j)
     {
      if(j&1)
      {
        for(int i=R-1;i>=0;--i)
            cout<<a[i][j]<<" ";
      }
      else
      {
        for(int i=0;i<R;++i)
            cout<<a[i][j]<<" ";
      }

     }
 }

 void spiralprint(int a[][10],int R,int C)
 {
     int rowfirst=0,rowlast=R-1,colfirst=0,collast=C-1;

     while(rowfirst<=rowlast && colfirst<=collast)
    {
        //print first row
        for(int j=rowfirst;j<=collast;++j)
        {
            cout<<a[rowfirst][j]<<" ";
        }
         rowfirst++;

        //print last column
        for(int j=rowfirst;j<=rowlast;++j)
         {
             cout<<a[j][collast]<<" ";
         }
         collast--;

        //print last row
        if(rowfirst<rowlast)
        {
            for(int j=collast;j>=colfirst;--j)
             {
                 cout<<a[rowlast][j]<<" ";
             }
             rowlast--;
        }

         //print first column
         if(colfirst<collast)
         {
            for(int j=rowlast;j>=rowfirst;--j)
             {
                 cout<<a[j][colfirst]<<" ";
             }
             colfirst++;
         }
    }
 }

 int main()
 {
    int R,C;
    int a[10][10];

    cout<<"enter no. of row & column \n";
    cin>>R>>C;

    readmatrix(a,R,C);           //read the matrix

    printmatrix(a,R,C);          //print the matrix

    waveprint(a,R,C);            //wave print of matrix

    spiralprint(a,R,C);
    return 0;
 }
