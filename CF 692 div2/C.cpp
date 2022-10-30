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

vector<int>g[100005];
bool vis[100005];
int coun=0, ans=0, cou=0;
void dfs(int nod, int par)
{

    if(vis[nod])
    {
        return;
    }
    coun++;
    vis[nod]=1;
    for(auto i:g[nod])
    {
        if(vis[i] and i!=par and coun>2)
        {
            //cout<<"here at " <<i<<endl;
            ans++;
            cou++;
        }
        else if(!vis[i]){
            cou++;
            dfs(i, nod);

        }
    }


}


int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        ans=0, coun=0, cou=0;
        for(int i=0; i<100005; i++)
        {
            g[i].clear();
            vis[i]=0;
        }
        ll n;
        cin>>n;
        ll m;
        cin>>m;

        int row[n+1], col[n+1];
        pair<int, int>p[m];
        for(int i=0; i<=n; i++)
        {
            row[i]=0;
            col[i]=0;
        }
        set<pair<int, int> >st;
        for(int i=0; i<m; i++)
        {
            int x, y;
            cin>>x>>y;
            row[x]=y;
            col[y]=x;
            p[i]={x,y};
            g[x].push_back(y);
           // g[y].push_back(y);
            st.insert(p[i]);
        }
        long long an=0, temp=0;
        coun=m;
        for(int i=0; i<m; i++)
        {
            int x=p[i].first, y=p[i].second;
            if(x==y)
            {
                vis[x]=1;
                continue;
            }
            if(st.find({y,x})!=st.end())
            {
                vis[x]=1;
                vis[y]=1;
                temp+=1;
            }
            an++;
        }
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                if(g[i].size()>0)
                {
                    int x=g[i][0];
                    dfs(i,x);
                   // cout<<endl;
                    coun=0;
                }

            }
        }


        an+=(temp/2);
        //cout<<ans<<endl;
        an+=ans;


        //cout<<cou<<endl;
        cout<<an<<endl;

    }
}



