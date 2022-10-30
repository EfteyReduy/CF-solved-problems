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

#define precision(x) cout<<fixed<<setprecision(x);
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;
using namespace __gnu_pbds;

///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///order_of_key() , find_by_order();

ll mod=1e9+7;


void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

const int sz=5000;
int parent[sz];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b){
        parent[b] = a;
    }
    else{

    }
}





main()
{
    fastIO();
    int t=1;
    cin>>t;
    vector<int>vec;
    for(int i=0; i<sz; i++)
    {
        parent[i]=i;
    }
    map<int , int >mp;
    int pos=0;
    vector<pair<pair<int, int>, int > > p;
    for(int i=0; i<t; i++)
    {
        int x, y, a;
        cin>>x;
        if(x==1)
        {
            cin>>a;
            vec.push_back(a);
            pos++;
        }
        else{
            cin>>y>>a;
            p.push_back({{a, y}, pos});
        }
    }

    int ben=vec.size();
    vector<int> ans;
    for(int i=p.size()-1; i>=0; i--)
    {
        for(int j=ben-1; j>=p[i].second; j--)
        {
            int x=find_set(vec[j]);
            ans.push_back(x);
        }
        ben=p[i].second;
        union_sets(p[i].first.first, p[i].first.second);
    }
    for(int i=ben-1; i>=0; i--)
    {
        int x=find_set(vec[i]);
        ans.push_back(x);
    }

    for(int i=ans.size()-1; i>=0; i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}



