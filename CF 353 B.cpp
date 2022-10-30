#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

main()
{
    ll n, a, b, c, d;
    cin>>n>>a>>b>>c>>d;

    ll x=a+b, y=a+c, xx=b+d, yy=d+c;
    ll red=max({x, y, xx, yy})-min({x, y, xx, yy});
    red=n-red;
    cout<<max((ll)0,n*red)<<endl;

}
