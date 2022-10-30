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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int ans=0, j=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>j)
            {
                ans++;
                j++;
            }
        }

        cout<<"Case #"<<cas<<": "<<ans<<endl;;

    }

    return 0;
}



