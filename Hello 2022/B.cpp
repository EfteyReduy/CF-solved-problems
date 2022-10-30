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
        if(lhs.F==rhs.F)
        {
            return lhs.S<rhs.S;
        }
        return lhs.F<rhs.F;
    }
};


///comparison structure to use customized set.............
struct cmpStruc {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.F==rhs.F)
        {
            return lhs.S<rhs.S;
        }
        return lhs.F>rhs.F;
    }
};


//set<pair<int, int>, cmpStruct> s;

///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first < b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
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
        pair<pair<int, int>, int>p[n];
        map<pair<int, int>, int>mp;

        set<pair<int, int>, cmpStruc >sr;

        set<pair<int, int>, cmpStruct >sl;
        int men=1e9+2, mex=-1, im, ix, cost=0;
//        cin>>men>>mex>>cost;
//        im=0, ix=0;
//        cout<<cost<<endl;
//        mp[{men, mex}]=cost;
//        p[0]={{men, mex}, cost};
        for(int i=0; i<n; i++)
        {
            int l, r, c;
            cin>>l>>r>>c;
            p[i]={{l, r}, c};

            if(mp[{l, r}]!=0){
                mp[{l, r}]=min(mp[{l, r}], c);
            }
            else{
                mp[{l, r}]=c;
            }
            sl.insert({l, c});
            sr.insert({r, c});
            auto x=*sl.begin();
            auto y=*sr.begin();

            cost=x.S+y.S;

            if(mp[{x.F, y.F}]!=0)
            {
                cost=min(cost, mp[{x.F, y.F}]);
            }
            cout<<cost<<endl;

//            if(l<men)
//            {
//                im=i;
//                men=l;
//            }
//            if(r>mex)
//            {
//                ix=i;
//                mex=r;
//            }
//
//            if(im==ix){
//                cout<<p[im].second<<endl;
//            }
//            else{
//                cout<<p[im].second+p[ix].second<<endl;
//            }

        }

    }
    return 0;
}



