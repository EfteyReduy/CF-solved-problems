#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);

    long long cum[n+1];
    cum[0]=0;
    for(int i=1; i<=n; i++)
    {
        cum[i]=cum[i-1]+arr[i-1];
    }

    long long ans=10000000000000000;
    for(int i=0; i<n; i++)
    {
        long long l=arr[i], lft=cum[i], rit=cum[n]-cum[i+1], kepl=(n-i-1)*(arr[i]);

        long long temp=rit-kepl;
        temp+=((i*arr[i])-lft);
        ans=min(ans,temp);


    }
    cout<<ans<<endl;

}
