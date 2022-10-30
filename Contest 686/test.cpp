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



typedef long long ll;
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pair :: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/
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
int loopat, depth;
bool vis[1000002];
vector<int>gr[100002];
void dfs(int node, int d)
{
    if(vis[node])
    {
        return;
    }
    else{
        vis[node]=1;
    }
    for(int i=0; i<gr[node].size(); i++)
    {
        if(vis[gr[node][i]] and gr[node][i]!=node)
        {
            loopat=gr[node][i];
            depth=d;
        }
        dfs(gr[node][i], d+1);
    }
}

int kount=0;

int iscyclic(int node,bool visited[],bool rec[],vector<int>g[])
{
    if(!visited[node])
    {
        visited[node] = true;
        rec[node] = true;
        vector<int>::iterator it;
        for(it=g[node].begin();it!=g[node].end();it++)
        {
            if(!visited[*it] && iscyclic(*it,visited,rec,g))
            {
                kount++;
            }
            else if(rec[*it])
                kount++;
        }
    }
rec[node] = false;
return kount;
}



main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int a, b;
            cin>>a>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(1, 0);
        cout<<loopat<<endl;
//        if(n>1)
//            cout<<((n-1)*(n-1))+2<<endl;
//        else
//            cout<<0<<endl;

    }
}



