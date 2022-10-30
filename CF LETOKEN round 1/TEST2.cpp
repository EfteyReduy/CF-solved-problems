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
#define flus cout.flush();
#define precision(x) cout<<fixed<<setprecision(x);
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;


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
        int n;
        cin>>n;
        int dis[n+1][n+1];
        cout<<"? "<<1<<endl;
        flus;
        int vis[n+1]={0};
        vis[1]=1;
        vector<pair<int, int> >edg;
        fardest=0;
        map<pair<int, int> , int>mp;
        map<int, vector<int>>coum;
        for(int i=1; i<=n; i++)
        {
            cin>>dis[1][i];
            coum[dis[1][i]].push_back(i);
            fardest=max(fardest, dis[1][i]);
            if(dis[1][i]==1)
            {
                edg.push_back({1, dis[1][i]});
                mp[{1, dis[1][i]}]++;
            }
        }
        int dp[fardest+3][2];
        dp[0][0]=dp[0][1]=1;
        dp[1][0]=dp[1][1]=coum[1].size();
        dp[2][0]=dp[2][1]=coum[2].size();
        for(int i=3; i<=fardest; i++)
        {
            dp[i][0]=dp[i-1][1];
            dp[i][1]=min(dp[i-1][1], dp[i-2][1])+coum[i].size();
        }
        int tobes, prevs=1;
        for(int i=1; i<=n; i++)
        {
            if(dis[1][i]==fardest and !vis[i])
            {
                tobes=i;
                break;
            }
        }
        while(mp.size()<n-1)
        {
            cout<<"? "<<tobes<<endl;
            for(int i=1; i<=n; i++)
            {
                cin>>dis[tobes][i];
            }
        }

    }

    return 0;
}





