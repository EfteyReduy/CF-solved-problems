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

struct cmpStruct {
    bool operator() (pair< pair<int, int>, pair<int, int> > const & lhs, pair< pair<int, int>, pair<int, int> > const & rhs) const
    {
        if(lhs.F.F==rhs.F.F)
        {
            if(lhs.F.S==rhs.F.S)
            {
                return lhs.S.F<rhs.S.F;
            }
            else{
                return lhs.F.S<rhs.F.S;
            }
        }
        else{
            return lhs.F.F<rhs.F.F;
        }
    }
};


main()
{
    fastIO();
    int t=1;
    cin>>t;
    int n=t;
    pair<pair<int, int>, pair<int, int> >p[n+1];
    map<int, map<int, map<int, int> > >m, ml;

    map<int, map<int, int> >mm;

    for(int i=0; i<n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        p[i+1]={{a, b}, {c, i+1}};
        map<int, int>m1;
        m[a][b][c]=i+1;
    }

    //sort(p, p+n, cmpStruct());

    int taken[n+1];
    memset(taken, 0, sizeof(taken));

    for(auto x:m)
    {
        for(auto y:x.second)
        {
            vector<int>vec;
            for(auto z:y.second)
            {
                vec.push_back(z.second);
            }
            if(vec.size()>1)
            {
                for(int i=1; i<vec.size(); i+=2)
                {
                    cout<<vec[i]<<" "<<vec[i-1]<<endl;
                    taken[vec[i]]=1;
                    taken[vec[i-1]]=1;
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(!taken[i])
        {
            mm[p[i].F.F][p[i].F.S]=i;
        }
    }

    for(auto y:mm)
    {
        vector<int>vec;
        for(auto z:y.second)
        {
            vec.push_back(z.second);
        }
        if(vec.size()>1)
        {
            for(int i=1; i<vec.size(); i+=2)
            {
                cout<<vec[i]<<" "<<vec[i-1]<<endl;
                taken[vec[i]]=1;
                taken[vec[i-1]]=1;
            }
        }
    }
    vector<int>vec;
    for(int i=1; i<=n; i++)
    {
        if(!taken[i])
        {
            ml[p[i].F.F][p[i].F.S][p[i].S.F]=i;
        }
    }
    for(auto it:ml)
    {
        vec.push_back(it.S.S.S.S);
    }

    for(int i=0; i<vec.size(); i+=2)
    {
        cout<<vec[i]<<" "<<vec[i+1]<<endl;
    }

    return 0;
}



 
