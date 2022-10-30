#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, q;
        cin>>n>>q;
        long long arr[n];
        bool x=true;
        cin>>arr[0];
        for(int i=1; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int j=0; j<q; j++)
        {
            int a, b;
            cin>>a>>b;
            swap(arr[a-1], arr[b-1]);
            long long ans=0;

            for(int i=0; i<n-1; i++)
            {
                if(arr[i]>arr[i+1])
                {
                    ans+=(arr[i]-arr[i+1]);
                }
            }
            ans+=arr[n-1];
            cout<<ans<<endl;
        }

    }
}
