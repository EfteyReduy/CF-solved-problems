#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

main()
{
    ll n, q, c;
    cin>>n>>q>>c;
    ll star[c+1][101][101];
    memset(star, 0, sizeof(star));

    while(n--)
    {
        ll i, j, s;
        cin>>i>>j>>s;
        star[0][i][j]+=s;
        for(int k=1; k<=c; k++)
        {
            star[k][i][j]+=((s+k)%(c+1));
            //cout<<star[k][i][j]<<" ";
        }
    }
    for(int i=0; i<=c; i++)
    {
        for(int j=0; j<=100; j++)
        {
            for(int k=1; k<101; k++)
            {
                star[i][j][k]+=star[i][j][k-1];
            }
        }
    }
    ll ans=0;
    while(q--)
    {
        int t, x, y, x1, y1;
        cin>>t>>x>>y>>x1>>y1;
        int i=t%(c+1);
        for(int j=x; j<=x1; j++)
            ans+=(star[i][j][y1]-star[i][j][y-1]);
        cout<<ans<<endl;
        ans=0;
    }
}
