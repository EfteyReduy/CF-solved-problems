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


void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


///comparison structure to use customized set.............
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

/// n^p when it can be a finite number---------------------------------------------------------------------------------------
ll power(ll n, ll p)
{
	if(p==0) return 1;
	if(p==1) return n;
	ll ans=1;
	while(p){
	    if(p&1) ans=ans*n;
        n=n*n;
        p=p/2;
	}
	return ans;
}

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        memset(arr, 0, sizeof(arr));
        pair<int, int>p[n];
        int j=0, k=0;

        vector<int>ans;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            p[i]={a, i};
            arr[a]++;
        }
        while(j<n){
            int x=0;
            for(int i=0; i<n+1; i++)
            {
                if(arr[i])
                {
                    x++;
                }
                else{
                    break;
                }
            }
            set<int>st;
            int i;
            for(i=j; i<n; i++)
            {
                if(p[i].F<x)
                {
                    st.insert(p[i].F);
                }
                if(st.size()==x)
                {
                    break;
                }
            }
            ans.push_back(x);
            for(k=j; k<=i; k++)
            {
                arr[p[k].F]--;
            }

            j=i+1;
        }
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


