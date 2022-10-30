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
#define MP make_pair

#define precision(x) cout<<fixed<<setprecision(x);

using namespace std;


main()
{
    int n, m, l, r;
    cin>>n>>m>>l>>r;

    //int a[n]={0},b[m]={0};
    Pii z[n], x[m];
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        z[i]=MP(a,b);
    }
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        x[i]=MP(a,b);
    }

    long long ans=0, cou=0;
    for(int i=l; i<r; i++)
    {
        for(int j=0; j<m; j++)
        {
            int a=x[j].F+i, b=x[j].S+i;
            for(int k=0; k<n; k++)
            {
                int mn=min(b,z[k].S);
                int mx=max(a, z[k].F);
                ans+=(mx-mn+1);
                if(ans)
                    break;
            }
        }
        if(ans)
        {
            cou++;
        }
        ans=0;
    }

    cout<<cou<<endl;

}
