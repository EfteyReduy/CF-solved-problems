#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long k;
        cin>>k;
        long long x=n*k, y=(1+n)/2;
        long long z=(y-1)*k;
        //int arr[x];
        long long ans=0, a;
        //cout<<y<<endl;
        for(int i=1; i<=z; i++)
        {
            cin>>a;
        }
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<= 1+n-y; j++)
            {
                cin>>a;
                if(j==1)
                    ans+=a;
            }
        }
        cout<<ans<<endl;
    }
}
