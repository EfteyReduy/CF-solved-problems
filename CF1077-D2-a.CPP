#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,k;
        cin>>a>>b>>k;
        long long ans=0;
        long long x=a-b, y=k/2;
        ans=x*y+(k%2)*a;
        cout<<ans<<endl;

    }
    return 0;
}
