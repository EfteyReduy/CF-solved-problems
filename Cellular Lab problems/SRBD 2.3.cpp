#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod=1e9+7;

void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


ll mpower(ll n, ll p)
{
	if(p==-1) p=mod-2;
	if(p==0) return 1;
	if(p==1) return n;
	ll ans=1;
	while(p){
		if(p&1) ans=((ans%mod)*n)%mod;
        n=((n%mod)*(n%mod))%mod;
		p=p/2;
	}
	return ans;
}

main()
{
    int t;
    cin>>t;
    for( int tt = 1; tt<=t; tt++)
    {
        long long m, n;
        cin>>m>>n;
        long long x = mpower(m, n);
        long long y = mpower(m, n-1);
        long long ans = x - y;
        ans+=mod;
        ans%=mod;
        cout<<"Case "<<tt<<": ";
        cout<<ans<<endl;
    }
}
