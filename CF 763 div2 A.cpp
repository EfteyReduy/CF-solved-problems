#include<bits/stdc++.h>

typedef long long ll;
using namespace std;



main()
{
    int t;
    cin>>t;
    while(t--){
        ll x, y, a, b, c, d;
        cin>>x>>y>>a>>b>>c>>d;

        ll ans=1e16;
        if(a<=c)
        {
            ans=min(ans, c-a);
        }
        else{
            ans=min(ans, (a-c)+(2*(x-a)));
        }

        if(b<=d)
        {
            ans=min(ans, d-b);
        }
        else{
            ans=min(ans, (b-d)+(2*(y-b)));
        }
        cout<<ans<<endl;

    }
}
