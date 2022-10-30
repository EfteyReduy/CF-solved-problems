#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef set<int> si;
typedef set<ll> sll;

typedef map<int, int> mii;
typedef map<ll, ll> mll;

const double pi = acos(-1.0);
const long long INF = 2e18;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define in insert
#define endl "\n"

#define sqr(a) ((a) * (a))
#define jor(a) !(a&1) //jor means EVEN number
#define bjor(a) (a&1) //bjor means ODD number

#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) //memset only for -1 and 0
//fill(a, a+n, 5) //fill for any value

#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);

void print(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}

#define watch(x) cout << (#x) << " is " << (x) << endl;

//-------------------------------------------------------------------

ll n, m, mod=1e9+7;

ll const mx = 1e3+5;

ll a[mx];

ll dp[mx][mx];

//state
//transition
//base
//return
//memorization

ll f(ll pos, ll sum){
    if(pos==n){
        if(sum==m) return 1;
        else return 0;
    }
    if(dp[pos][sum]!=-1) return dp[pos][sum];

    ll ans1=0, ans2=0;

    if(sum+a[pos]<=m) ans1 = f(pos, sum+a[pos]);///the only change here is, pos instead of pos+1
    ans2 = f(pos+1, sum);

    dp[pos][sum]= ans1 + ans2;
}

int main()
{
    FAST
   // fileRead

    cin>>n;
    for0(i,n) cin>>a[i];
    cin>>m; ///we have to make m

    mem(dp, -1);

    cout<<f(0, 0);

/*
    test case:
    5
    1 2 3 4 5
    6

    ans: 3
    1+2+3, 1+5, 2+4
    */
}
