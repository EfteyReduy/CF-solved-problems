
#include<bits/stdc++.h>
#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;

main()
{
    long long n, s, sum=0;
    cin>>n>>s;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    long long flex=sum-s;

    long long ans[n];
    for(int i=0; i<n; i++)
    {
        long long b=s-arr[i],a=sum-arr[i], hi=min(arr[i],s-n+1), lo, l=0;

        lo=max(l,s-a-1);
        ans[i]=arr[i]-abs(hi-lo);
        cout<<ans[i]<< " ";


    }
    cout<<endl;

}
