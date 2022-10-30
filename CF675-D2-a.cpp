#include<bits/stdc++.h>
#define ll long long
using namespace std;

main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        ll arr[n][m];
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                cin>>arr[i][j];
            }
        }
        ll ans=0;
        for(ll i=0; i<(n+1)/2; i++)
        {
            for(ll j=0; j<(m+1)/2; j++)
            {
                ll cou=0;
                ll a=arr[i][j], b=arr[i][m-j-1], c=arr[n-i-1][j], d=arr[n-i-1][m-j-1];
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                ll  x=abs(a-b)+abs(a-c)+abs(a-d);
                ll  y=abs(b-a)+abs(b-c)+abs(b-d);
                ll z=abs(a-c)+abs(b-c)+abs(c-d);
                ll zz=abs(a-d)+abs(b-d)+abs(c-d);

                cou=min(x,min(y, min(z,zz)));
                if(i==n-i-1 or j==m-j-1)
                    cou/=2;
                ans+=cou;


            }
        }
        cout<<ans<<endl;


    }
}
