#include<iostream>
using namespace std;

int find_set_bit_pos(int n)
{
    int mask=0,cn=0;
    while((n&1)==1)
    {
        mask=(n&1);
        n=n>>1;
        ++cn;

        if(mask==1)
            return cn;
    }
}
int main()
{
    int num,a[100005],res1=0;
    cout<<"enter the size of number \n";
    cin>>num;
    for(int i=0;i<num;++i)
    {
        cin>>a[i];
        res1=res1^a[i];
    }

    int set_bit_pos=find_set_bit_pos(res1);
    int mask=1<<(set_bit_pos-1);

    int x=0;
    int y=0;

    for(int j=0;j<num;++j)
    {
        if((a[j]&mask)>0)
            x=x^a[j];
    }

    y=res1^x;
    if(x<y)
        cout<<x<<" "<<y<<endl;
	else
        cout<<y<<" "<<x<<endl;
	return 0;
}
