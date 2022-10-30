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
    while(t--)
    {
        int n;
        cin>>n;

        map<int, int>p;
            int a, b;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            p[(a+b-1)]++;
        }
        bool pos=true;
        for(auto it:p)
        {
            if(it.first>n)
            {
                int x=(2*n) - it.first;
                if(x==it.second)
                {
                    pos=false;
                    break;
                }
            }
            else{
                int x=it.first;
                if(x==it.second)
                {
                    pos=false;
                    break;
                }
            }
        }

        if(pos)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}




