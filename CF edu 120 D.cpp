#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define PP pop_back
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define I insert
#define E erase
#define B back
#define C clear
#define SZ size
#define Vi vector<int>
#define Vll vector<ll>
#define Vpii vector<pair<int, int> >
#define Vpll vector<pair< ll, ll> >

#define precision(x) cout<<fixed<<setprecision(x);
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///order_of_key() , find_by_order();

ll mod=998244353;



// function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll * x, ll * y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


ll modInverse(ll a, ll m)
{
	ll x, y;
	ll g = gcdExtended(a, m, &x, &y);
	if (g != 1)
        return -1;
		//printf("Inverse doesn't exist");
	else
	{
		ll res = (x % m + m) % m;
		//printf("Modular multiplicative inverse is %d", res);
		return res;
	}
}



void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



main()
{
    fastIO();
    ll n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    ll fac[n+2], ifac[n+2];
    fac[0]=1;
    ifac[0]=1;
    for(ll i=1; i<=n; i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }

    for(ll i=1; i<=n; i++)
    {
        ll x=modInverse(i, mod);
        ifac[i]=x*ifac[i-1];
        ifac[i]%=mod;
    }

    vector<ll>ones;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1')
        {
            ones.push_back(i);
        }
    }

    ll i=0, j=0;
    ll cou=0;

    ll ans=1;
    if(k<=0)
    {
        cout<<ans<<endl;
        return 0;
    }
    if(ones.size()>=k)
    {
        ones.push_back(n);

        ll x=fac[ones[k]];
        x*=ifac[k];
        x%=mod;
        x*=(ifac[ones[k]-k]);
        x%=mod;
        ans=x;
        j=k;
        while(ones[j]<n)
        {
            j++;
            ll a=ones[j];
            ll b=a-ones[i]-1;
            x=fac[b]*ifac[k];
            x%=mod;
            x*=(ifac[b-k]);
            x%=mod;

            b=ones[j-1]-ones[i]-1;
            ll y=fac[b]*ifac[k-1];
            y%=mod;
            y*=ifac[b-k+1];
            y%=mod;
            i++;

            ans+=x;
            ans-=y;
            ans+=mod;
            ans%=mod;

        }
    }

    ans%=mod;
    cout<<ans<<endl;

    return 0;
}








