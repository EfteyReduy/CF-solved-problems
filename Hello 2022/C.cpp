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

#define precision(x) cout<<fixed<<setprecision(x)
#define db(x) cout<<#x<<" = "<<x<<endl

#define on_bits(x) __builtin_popcount(x)
#define off_bits(x) (int)log2(x)-on_bits(x)+1

using namespace std;
using namespace __gnu_pbds;

ll mod=1e9+7;



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



ll ncrarr[1001][1001]={0};
void nCrTable(){
    for(int i=0; i<1001; i++)
    {
        ncrarr[0][i]=1;
        ncrarr[i][0]=1;
    }

    for(int i=1; i<1001; i++)
    {
        for(int j=1; j<1001; j++)
        {
            ncrarr[i][j]=ncrarr[i-1][j]+ncrarr[i][j-1];
            ncrarr[i][j]%=mod;
        }
    }
}
///ncr from pre computed array ..................................................................
ll nCr(int n, int r)
{
    int x=min(r, n-r);
    return ( ncrarr[n-x][x]);
}

///ncr for a single value ......................................................................
ll ncr(ll n, ll r)
{
    ll ans=1;
    if(n<r)
    {
        return 0;
    }

    r=max(r, n-r);
    if(r==n)
    {
        return 1;
    }
    for(ll i=r+1; i<=n; i++)
    {
        ans*=i;
        ans%=mod;
        ans*=modInverse(i-r, mod);
        ans%=mod;
    }
    return ans%mod;
}
ll fact(ll n)
{
    ll ans=1;
    for(ll i=1; i<=n; i++)
    {
        ans*=i;
        ans%=mod;
    }
    return ans;
}


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

/// Siv's algorithm  ==================================================================================
///====================================================================================================
bool status[400000];
int dif[100000]={0};

void siv(int N) {
    int sq = sqrt(N);

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

void setDif(){
    int j=0;
    for(int i=2; i<400000 ; i++)
    {
        if(status[i]==0)
        {
            dif[j]=(i);
            j++;
        }
    }
}

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

//set<pair<int, int>, cmpStruct> s;

///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
}

/// n^p when it can be a finite number---------------------------------------------------------------------------------------
ll power(ll n, ll p)
{
	if(p==0) return 1;
	if(p==1) return n;
	ll ans=1;
	while(p){
	    if(p&1) ans=ans*n;
        n=n*n;
        p=p/2;
	}
	return ans;
}

/// i^n when it can be a large number................................................................
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





void NO(){
    cout<<"NO"<<"\n";
}
void YES(){
    cout<<"YES"<<"\n";
}
void No(){
    cout<<"No"<<"\n";
}
void Yes(){
    cout<<"Yes"<<"\n";
}

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++)
        {
            arr[i]=i;
        }
        bool vis[n+1];
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            if(vis[i])
            {
                continue;
            }
            cout<<"? "<<i<<endl;
            cout.flush();
            int x;
            cin>>x;
            int y=x;
            vector<pair<int, int> >vp;
            while(!vis[x])
            {
                cout<<"? "<<i<<endl;
                cout.flush();
                cin>>x;
                //swap(arr[x], arr[y]);
                //cout<<"swapping "<< arr[x]<<" "<<arr[y]<<endl;
                vis[y]=1;
                vp.push_back({x, y});
                y=x;
            }
            for(int ii=0; ii<vp.size()-1; ii++)
            {
                swap(arr[vp[ii].first], arr[vp[ii].second]);
                //cout<<vp[ii].F<<" "<<vp[ii].S<<endl;
            }

            vis[x]=1;
        }
        cout<<"! ";
        for(int i=1; i<=n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout.flush();

    }
    return 0;
}



