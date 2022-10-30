#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int c=1;
    long long ans=0;
    while(c<n)
    {
        int x=n-1;
        ans+=(x)/c;
        c++;

    }
    cout<<ans<<endl;
}
