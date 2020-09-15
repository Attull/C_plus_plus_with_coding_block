#include<iostream>
#include<set>
using namespace std;

int main()
{
    int no_of_trans,frds;
    cout<<"Maximum transaction & No. of frds :\n";
    cin>>no_of_trans>>frds;

    int x,y,amount;               //x and y represent person numbr

    //make a 1D array to store the net amount that each person will have to take at the end
    int net[10000]={0};

    while(no_of_trans--)
    {

        cin>>x>>y>>amount;
        cout<<x<<" person give "<<amount<<"rs to person "<<y<<endl;
        net[x]-=amount;           //bcoz x is giving money to y
        net[y]+=amount;           //bcoz y is receiving money from x

    }

    multiset<int> m;

    //initialise a list & sort it => multiset
    for(int i=0;i<frds;++i)
    {
        if(net[i]!=0)
        {
            m.insert(net[i]);
        }
    }

    //pop out two person(left and right) and try to settle them
    int cnt=0;     //two count how much transaction need for settlement
    while(!m.empty())
    {
        auto low=m.begin();
        auto high=prev(m.end());

        int debit=*low;             //minimum amount that can debit
        int credit=*high;           //maximum amount that can be credit

        //after pointing them, erase them from set
        m.erase(low);
        m.erase(high);

        //settlement
        int settlement_amount=min(-debit,credit);
        cnt++;

        debit+=settlement_amount;     //increase debit amount i.e we give this amount to person
        credit-=settlement_amount;    //decrease credit amount by above settlement amount

        if(debit!=0)
            m.insert(debit);

        if(credit!=0)
            m.insert(credit);
    }
    cout<<"total number of transaction for settlement : \t"<<cnt<<endl;
}
