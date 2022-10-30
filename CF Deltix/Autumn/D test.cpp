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

ll mod=1e9+7;




void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int siz[100000]={0};
int parent[100000]={0};
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;

}



int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

int sz=0;

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}


vector<int> g[1002];
bool vis[1002];
int cou=0;
void dfs(int a)
{
    if(!vis[a])
    {
        vis[a]=1;
        cou++;
        for(auto it:g[a])
        {
            dfs(it);
        }
    }
}

main()
{
    fastIO();

    int n, t, ans=1;
    cin>>n>>t;

    for(int i=0; i<t; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);

        dfs(a);
        ans=max(ans, cou);
        memset(vis, 0, sizeof(vis));
        cout<<ans-1<<endl;
        cou=0;
    }


    return 0;
}






