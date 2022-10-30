#include<bits/stdc++.h>



using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x, y;
        cin>>x;
        map<long long, int>mp;

        long long arr[x], a, b=-1e9;
        a=-b;
        for(int i=0; i<x; i++)
        {
            cin>>arr[i];
            mp[arr[i]]++;
            a=min(arr[i], a);
            b=max(arr[i], b);
        }

        sort(arr, arr+x);
        long long m, n, ans=2e9;
        for(int i=1; i<x-1; i++)
        {
            m=arr[i];
            long long ned=b-m+a;
            if(arr[i]==ned)
            {
                continue;
            }
            int j=lower_bound(arr, arr+x, ned)-arr;
            if(j==i)
            {
                continue;
            }
            if(j==x-1)
            {
                ans=min(ans, abs(ned-arr[j-1]));
                continue;
            }
            if(arr[j]==ned)
            {
                ans=0;
                //cout<<"hare at j= "<<j<<endl;
                break;
            }
            else if(j>0){
                long long dif=min(abs(ned-arr[j]), abs(ned-arr[j-1]));
                ans=min(ans, dif);
            }

        }
        ans=min(ans, b-arr[1]);
        ans=min(ans, arr[x-2]-arr[0]);
        long long jj=(arr[0]+arr[x-1]);
        if(jj%2==0)
        {
            jj/=2;
            if(mp[jj]>1)
                ans=0;
        }
        cout<<ans<<endl;

    }
}


