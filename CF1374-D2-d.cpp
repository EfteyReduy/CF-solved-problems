#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n>>k;
        long long arr[n], mex=0;
        for(int i=0;i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]%k)
                mex=max(mex, arr[i]);
            arr[i]%=k;

        }
        long long x=(mex+k-1)/k;
        x=x*k;



        sort(arr,arr+n);
        long long ans=0;
        int j=0;
        while(arr[j]==0)
        {
            j++;
        }
        //cout<<"value of j ="<<j<<endl;

        for(int i=j; i<n; i++)
        {
            long long cou=1;
            while(arr[i]==arr[i+1] and i<n-1)
            {
                cou++;
                i++;
            }
            long long a=k*cou-arr[i]+1;
            ans=max(ans, a);
        }
        //ans=max(ans,x);
        cout<<ans<<endl;
    }
}
