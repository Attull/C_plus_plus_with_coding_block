    #include<iostream>
    #include<string.h>
    using namespace std;

    #define ll long long
     ll arr[100001],freq[100001];
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            memset(freq,0,sizeof(freq));

            freq[0]=1;                  //sum of null subarray is 0
            int sum=0;n;
            for(int i=0;i<n;++i)
            {
                cin>>arr[i];
                sum+=arr[i];          // cummalative sum logic
                sum=(sum+n)%n;        //to avoid negative number
                freq[sum]++;
            }

            ll ans=0;
            for(int i=0;i<n;++i)
            {
                int m=freq[i];
                ans+=(m*(m-1))/2;     //mC2
            }
            cout<<ans<<endl;
         }
    }
