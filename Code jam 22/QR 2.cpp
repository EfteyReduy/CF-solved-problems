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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///order_of_key() , find_by_order();

ll mod=1e9+7;
void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

main()
{
    fastIO();
    int t=1;
    cin>>t;
    int cas=0;
    while(cas++<t)
    {
        int C, M, Y, K;
        C = M = Y = K = 1e6;
        for(int i=0; i<3; i++)
        {
            int c, m, y, k;
            cin>>c>>m>>y>>k;
            C = min(C, c);
            M = min(M, m);
            Y = min(Y, y);
            K = min(K, k);
        }

        cout<<"Case #"<<cas<<": ";

        if(C + M + Y + K < 1e6){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            int req = 1e6;
            cout<<C<<" ";
            req -= C;
            cout<<min(req, M)<<" ";
            req = max(0, req-M);

            cout<<min(req, Y)<<" ";
            req = max(0, req-Y);

            cout<<min(req, K)<<endl;
            req = max(0, req-K);
        }

    }

    return 0;
}


