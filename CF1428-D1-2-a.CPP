#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long ans=0, a, b, x, y;
        cin>>a>>b>>x>>y;
        x=abs(a-x);
        y=abs(b-y);

        if(x==0 or y==0)
            ans=-2;

        ans+=(x+y+2);
        cout<<ans<<endl;

    }
}
