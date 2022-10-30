#include<bits/stdc++.h>


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

void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

typedef long long ll;

///comparison structure to use customized set.............
struct cmpStruct {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first < rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const ll &a, const ll &b)
{
    return a>b;
}
/**

..........................for priority queue reference.........................

https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/?ref=rp

**/

int gcdExtended(ll a, ll b, ll* x, ll* y)
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




ll mod=1e9+7;
ll ncr(ll n, ll r)
{
    r=min(r, n-r);
    ll temp=1;
    int j=1;
    for(int i=r+1; i<=n; i++)
    {
        temp*=i;
        temp%=mod;

        ll x=modInverse(j,mod);
        temp=temp*x;
        temp%=mod;
        j++;
    }
    return temp;
}

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        ll arr[n+1];
        memset(arr, 0, sizeof(arr));
        map<ll, ll>mp;
        for(int i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            arr[a]++;
            //mp[a]++;
        }
        //sort(arr, arr+n, desc);
        ll kk=k, ans=0;
        for(int i=n; i>=0; i--)
        {
            kk-=(arr[i]);
            if(kk<=0)
            {
                kk+=arr[i];
                //cout<<kk<<" "<<arr[i]<<endl;
                ans=ncr(arr[i], kk);
                break;
            }
        }
        cout<<ans<<endl;


    }
    return 0;
}


