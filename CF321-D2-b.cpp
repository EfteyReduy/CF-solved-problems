#include<bits/stdc++.h>
#define ll long long

#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;

main()
{
    ll n, d;
    cin>>n>>d;
    vector<ll>vc;
    pair<ll,ll>p[n];
    for(int i=0; i<n; i++)
    {
        ll a, b;
        cin>>a>>b;
        p[i]={a,b};
        vc.push_back(a);

    }
    sort(p, p+n);
    sort(vc.begin(), vc.end());

    ll cum[n];/// cum for cumulative sum........ (^_^)...
    cum[0]=p[0].second;
    for(int i=1; i<n; i++)
    {
        cum[i]=cum[i-1]+p[i].second;
    }

    ll pre=0, ans=0;
    for(int i=0; i<n; i++)
    {
        ll x=p[i].first+d-1;

        int y=(upper_bound(vc.begin(), vc.end(), x))-vc.begin()-1;

        ll z= cum[y]-pre;
        ans=max(ans, z);
        pre=cum[i];
    }
    cout<<ans<<endl;
}
