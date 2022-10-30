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

int main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        int n, m;
        cin>>n>>m;
        int mat[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat[i][j]=-1e8;
            }
        }
        int inf=-1e8;
        for(int i=0; i<m; i++)
        {
            int a, b, c;
            cin>>a>>b>>c;
            mat[a][b]=max(mat[a][b], -c);
            mat[b][a]=mat[a][b];
        }
        int dest;
        cin>>dest;
        int ans[n];
        for(int i=0; i<n; i++)
        {
            ans[i]=-1e8;
        }

        priority_queue<pair<int, int> >pq;
        pq.push({0, dest});
        int vis[n];
        int temp=-1e8;
        memset(vis, 0, sizeof(vis));
        while(!pq.empty())
        {
            pair<int, int>p=pq.top();
            pq.pop();

            ans[p.second]=max(p.first, ans[p.second]);
            //cout<<p.second<<" "<<p.first<<endl;

            vis[p.second]=1;
            for(int j=0; j<n; j++)
            {
                if(mat[p.second][j]!=inf and !vis[j])
                {
                    pq.push({min(mat[p.second][j], p.first), j});
                }
            }
        }
        ces(cas);
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            if(ans[i]==-1e8)
            {
                cout<<"Impossible"<<endl;
                continue;
            }
            cout<<abs(ans[i])<<endl;
        }
        cout<<endl;

    }
}


