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
        return b1.Height > b2.Height;
    }
};






main()
{
    fastIO();
    int t=1;
    cin>>t;
    for(int tcase=1; tcase<=t; tcase++)
    {
        int n;
        cin>>n;
        int mat[n][n], cost[n][n];
        int r[n], c[n];
        int check_r[n], check_c[n];

        priority_queue<box,vector<box>,CompareHeight>pq;
        for(int i=0; i<n; i++)
        {
            check_r[i]=check_c[i]=0;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]==-1)
                {
                    check_r[i]++;
                    check_c[j]++;

                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>cost[i][j];
                if(mat[i][j]==-1)
                {
                    pq.push(box(cost[i][j], i, j));
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            cin>>r[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>c[i];
        }

        while(!pq.empty())
        {
            box b=pq.top();
            pq.pop();
            int x=b.i, y=b.j, cost=b.Height;



        }


    }
    return 0;
}


