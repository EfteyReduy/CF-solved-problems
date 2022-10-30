#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    long long ans=1, mod=1e9+7, sub=1;

    for(int i=0; i<n; i++)
    {
        ans=ans*27;
        ans%=mod;
        sub*=7;
        sub%=mod;
    }

    ans=ans-sub+mod;
    ans%=mod;
    cout<<ans<<endl;

}
