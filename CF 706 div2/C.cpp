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
        int n, j=0, k=0;
        cin>>n;
        ll miner[n], mine[n], nmine;
        for(int i=0; i<2*n; i++)
        {
            ll x, y;
            cin>>x>>y;
            if(x==0)
            {
                miner[j]=(abs(y));

                j++;
            }
            else{
                mine[k]=(abs(x));
                k++;
            }
        }
        sort(miner, miner+n);
        sort(mine, mine+n);
        //sort(nmine.rbegin(),nmine.rend());
        double nm, m;
        nm=0, m=0;
        for(int i=0; i<n; i++)
        {
            m=(double)((miner[i]*miner[i])+(mine[i]*mine[i]));
            nm+=sqrt(m);
        }

        precision(10);
        cout<<nm<<endl;
    }

    return 0;
}



