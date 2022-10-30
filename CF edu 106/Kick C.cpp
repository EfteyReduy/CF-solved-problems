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

struct box{
ll Height;
int i, j;
box(ll Height, int i, int j):Height(Height),i(i),j(j){}
};

struct CompareHeight {
    bool operator()(box const& b1, box const& b2)
    {
        return b1.Height < b2.Height;
    }
};





main()
{
    fastIO();
    int t=1;
    cin>>t;
    for(int tcase=1; tcase<=t; tcase++)
    {
        int n, k;
        int c, r;
        cin>>r>>c;
        ll g[r][c];
        priority_queue<box,vector<box>,CompareHeight>pq;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>g[i][j];
                pq.push(box(g[i][j], i, j));
            }
        }
        bool vis[r][c];
        ll ans=0;
        memset(vis, 0, sizeof(vis));
        while(!pq.empty())
        {
            box b=pq.top();
            pq.pop();
            //cout<<b.Height<<endl;
            int x=b.i, y=b.j;
            ll h=b.Height;
            if(vis[x][y])
            {
                continue;
            }
            else{
                vis[x][y]=1;
            }
            if(x+1<r)
            {
                ll a=g[x+1][y];
                if((h-a)>1)
                {
                    ans+=(h-a-1);
                    g[x+1][y]=h-1;
                    pq.push(box(h-1, x+1, y));
                }
            }
            if(x-1>=0)
            {
                ll a=g[x-1][y];
                if((h-a)>1)
                {
                    ans+=(h-a-1);
                    g[x-1][y]=h-1;
                    pq.push(box(h-1, x-1, y));
                }
            }
            if(y+1<c)
            {
                ll a=g[x][y+1];
                if((h-a)>1)
                {
                    ans+=(h-a-1);
                    g[x][y+1]=h-1;
                    pq.push(box(h-1, x, y+1));
                }
            }
            if(y-1>=0)
            {
                ll a=g[x][y-1];
                if((h-a)>1)
                {
                    ans+=(h-a-1);
                    g[x][y-1]=h-1;
                    pq.push(box(h-1, x, y-1));
                }
            }
        }

        cout<<"Case #"<<tcase<<": "<<ans<<endl;

    }
    return 0;
}


