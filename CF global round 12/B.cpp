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

bool vis[1000];
int dd[1000];
vector<int>g[1000];
void dfs(int node, int dep)
{
    if(vis[node])
        return;
    vis[node]=1;
    dd[node]=dep;
    for(int i=0; i<g[node].size(); i++)
    {
        dfs(g[node][i], dep+1);
    }
}


int main()
{

    int t=1;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<1000; i++)
        {
            vis[i]=0;
            dd[i]=0;
        }
        int n, k;
        cin>>n>>k;
        pair<int, int>p[n];
        for(int i=0; i<n; i++)
        {
            int x, y;
            cin>>x>>y;
            p[i]={x,y};
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    int a=p[i].first, b=p[i].second, c=p[j].first, d=p[j].second;
                    int dis=abs(a-c)+abs(b-d);
                    if(dis<=k)
                    {
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
        }

        int cou=0;
        for(int i=0 ; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, 0);
                cou++;
            }
        }
        if(cou>1)
        {
            cout<<-1<<endl;
        }
        else{

        }

        for(int i=0; i<1000; i++)
        {
            g[i].clear();
            vis[i]=0;
            dd[i]=0;
        }

    }


}


