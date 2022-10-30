
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
///==================================================================================================

#define SSA(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});//sorting array of string in ascending order
#define SSD(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() > b.size();});//sorting array of string in descending order



typedef long long ll;
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pair :: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/

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
///---------------------------------------------------------------------------------------
/// for debugging

#define printLine() cout << "----------" << endl;

#ifndef LOCAL
#define watch(x) cerr << #x <<" is "; _print(x); cerr << endl;
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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
void ces(int cas)
{
    cout<<"Case "<<cas<<": ";
}
priority_queue<pair<int, int >>pq;

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll k, m;
        cin>>k>>m;

        ll lo=1, hi=2*k;
        ll ans=0;
        while(lo<hi)
        {
            ll mid=(lo+hi)/2;
            bool pos=false;

            ll x=mid-1, y;
            //db(x);
            y=x-1;

            if(x<=k)
            {
                x=x*(x+1)/2;
            }
            else{
                ll tt=2*k-mid;
                x=(k*(k+1)/2)+(k*(k-1)/2)-(tt*(tt+1)/2);
            }

            if(x<m)
            {
                pos=true;
            }
           // cout<<"hare at lo = "<<lo<<" hi = "<<hi<<" mid = "<<mid<<" x = "<<x<<endl;
            if(pos)
            {
                ans=max(ans, mid);
                lo=mid+1;
            }
            else{
                hi=mid;
            }

        }
        cout<<ans<<endl;

    }

    return 0;
}


