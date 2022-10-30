#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>


typedef unsigned long long int ull;
#define ll long long
//#define int ll
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

///order_of_key() , find_by_order();

void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
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

bool custom_s(const pair<int,int> &a,  const pair<int,int> &b)
{
    if(a.first==b.first)
    {
        return a.second>b.second;
    }
    return a.first<b.first;
}

struct custom_sort {
    bool operator() (pair<int, int> const & a, pair<int, int> const & b) const
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};

struct sort_sec {
    bool operator() (pair<int, int> const & a, pair<int, int> const & b) const
    {
        if(a.F==b.F)
        {
            return a.S<b.S;
        }
        return a.S<b.S;
    }
};


///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
}
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


typedef tree<pair<int, int>, null_type, custom_sort, rb_tree_tag, tree_order_statistics_node_update> custom_set;
main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        Pii p[n*m];
        vector<pair<int, int> >vp[n];
        for(int i=0; i<n*m; i++)
        {
            int a;
            cin>>a;
            p[i]={a, i+1};
        }
        sort(p, p+(n*m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                vp[i].PB(p[i*m +j]);
            }
            sort(vp[i].begin(), vp[i].end(), sort_sec() );
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            custom_set s;
            for(int j=0; j<m; j++)
            {
                int x=s.order_of_key(vp[i][j]);
                ans+=x;
                s.insert(vp[i][j]);

            }
        }
        cout<<ans<<endl;
    }

    return 0;
}


