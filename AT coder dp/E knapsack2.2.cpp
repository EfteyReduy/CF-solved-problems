#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

ll dp[101][100001], ans=0, fin=0;
pair<ll, ll> v[101];
ll n, w;
ll f(ll p, ll profit, ll wsum){
    if(p==n){
        if(wsum>w) return -1e18;
        return profit;
    }
    if(dp[p][profit]!=-1) return dp[p][profit];

    ll ans=0;
    ans = f(p+1, profit+v[p].second, wsum+v[p].first);
    ans = max(ans, f(p+1, profit, wsum));

    return dp[p][profit]=ans;
    cout<<ans<<" ";
}

int main()
{
    memset(dp, -1, sizeof(dp));


    cin>>n>>w;
    for(int i=0; i<n; i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    ll a=f(0,0,w);
    cout<<a<<endl;
    cout<<fin<<endl;
}
