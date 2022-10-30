#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


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
void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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




bool status[1000000];
//int dif[100000]={0};
ll prim[78500];
void siv(ll N) {
    ll sq = sqrt(N);

    for (int i = 4; i <= N; i += 2) {
        status[i] = 1;
    }

    for (int i = 3; i <= sq; i += 2) {
        if (status[i] == 0) {
            for (int j = i * i; j <= N; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}
int j=0;
void setDif(){

    for(int i=2; i<1000000 ; i++)
    {
        if(status[i]==0)
            prim[j]=i, j++;
    }
}


int main()
{
    fastIO();
    ll t, mod=1000000007;
    siv(1000000);
    setDif();
    cin>>t;
    while(t--)
    {
        ll n, ans;
        cin>>n;
        ans=n%mod;
        bool pos=false;
        for(int it=0; prim[it]*prim[it]<=n and it<j; it++)
        {
            ll i=prim[it];
            if(n%i==0)
            {
                ll x=modInverse(i, mod);
                //cout<<x<<endl;
                x=x*ans;
                //cout<<x<<endl;
                x%=mod;
                //cout<<x<<endl;
                ans=ans*x;
                ans%=mod;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
