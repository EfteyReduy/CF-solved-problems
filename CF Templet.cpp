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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///order_of_key() , find_by_order();

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
typedef tree<int, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> order_set;
///order_of_key() , find_by_order();

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
/**

..........................for priority queue reference.........................

https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/?ref=rp

**/

priority_queue<pair<int, int >>pq;

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ordered_set oss;
        pair<int, int>p={1,2};
        oss.insert(1);
    }
    string sr;
    getline(cin,sr);

    string st;
    cin>>st;
    size_t f=sr.find(st);
    if(sr.find("row",f+1,2)!=std::string::npos)
    cout<<st<<" found at "<<sr.find("row", f+1, 2)<<endl;
    return 0;
    //Start code from here........
    vector<string>s;
    for(int i=0; i<9; i++)
    {
        string str;

        cin>>str;
        s.push_back(str);
    }
    SSA(s);
    sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});

    return 0;
}


/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 🙁 )
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing 😕
*/


/**
 * Use pen and paper. Solve on paper then code.
 * If there is some reasoning e.g. sequence/paths, try printing first 100 elements or 100 answers using brute and observe.
 * Read question with extreme caution. Sometimes we make question complex due to misunderstanding.
 * Prefix sum and suffix sum is highly usable concept, look for it.
 * Think of cleanest approach. If too many if else are coming then its indication of WA.
**/
