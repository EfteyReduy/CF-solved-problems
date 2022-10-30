#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


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

ll mod=1e9+7;

ll powr(ll i, ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2)
        {
            ans=ans*i;
            ans%=mod;
        }
        else{
            i=i*i;
            i%=mod;
        }
        n=n/2;
    }
    return ans;
}
int main()
{
    fastIO();
    string s;
    cin>>s;
    long long n=s.length();
    long long pr=powr(2,n-1),temp=0, ans=0, t=1, mib;
    mib=modInverse(2,mod);

    for(long long i=n-1; i>=0; i--)
    {
        long long dig=s[i]-'0';
        ll a=((i+1)*(i));
        a%=mod;
        a*=mib;
        a%=mod;
        a*=t;
        a%=mod;
        a*=dig;
        a%=mod;

        if(dig)
            ans+=a;
        ans%=mod;

        t=t*10;
        t%=mod;
    }
    ll x=1;
    t=1;
    ll a=0;
    for(int i=n-2; i>=0; i--)
    {
        long long dig=s[i]-'0';

        a+=((x)*(t));
        x++;
        a%=mod;
        ans+=(a*dig);
        ans%=mod;

        t=t*10;
        t%=mod;
    }





    cout<<ans<<endl;
}
