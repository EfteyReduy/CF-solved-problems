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

//bit on[make 1, use set], bit off[make 0, use reset], check bit[on or off, use check]

int biton(int N, int pos){
    return N = N | (1<<pos);
}

int bitoff(int N, int pos){
    return N = N & ~(1<<pos);
    //or return N = N & !(1<<pos);
}

int flipbit(int N, int pos){
    return N = N ^ (1<<pos);
}

bool bitcheck(int N, int pos){ // if returns any num then bit is on, if returns 0 then bit is off
    return (bool)(N & (1<<pos));
}

//-------------------------------------------------------------------

ll n, m, mod=1e9+7;

ll const mx = 1e5+5;

ll a[mx], b[mx];

ll dp[mx][2];

//state
//transition
//base
//return
//memorization

ll f(ll pos, ll x){
    if(pos==n) return 0;
    if(dp[pos][x]!=-1) return dp[pos][x];
    ll ans=0;
    if(x){
        ans = a[pos] + f(pos+1, x^1);
        ans = max(ans, f(pos+1, x));
    }
    else{
        ans = b[pos] + f(pos+1, x^1);
        ans = max(ans, f(pos+1, x));
    }
    return dp[pos][x] = ans;
}

int main()
{
    FAST

    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        cin>>n;
        for0(i,n) cin>>a[i];
        for0(i,n) cin>>b[i];

        mem(dp, -1);
        ll A = f(0,0);

        mem(dp, -1);
        ll B = f(0,1);

        cout<<max(A,B);
    }
}
