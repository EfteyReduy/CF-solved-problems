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

bool status[1000002];
int dif[100000]={0};

void siv(int N) {
    int sq = sqrt(N);

    for (int i = 4; i <= N; i += 2) {
        status[i] = 1;
    }

    for (int i = 3; i <= sq; i += 2) {
        if (status[i] == 0) {
            for (int j = i * i; j <= N; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}


main()
{
    siv(1000002);

    vector<ll> prim;
    for(int i=2; i<1000002; i++)
    {
        if(status[i]==0)
            prim.push_back(i);
    }

    int t;
    cin>>t;
    while(t--)
    {
        ll n, m, x, y;
        cin>>n>>m;


        vector<ll>d;

       // int pn[1000000], pm[1000000];

        if(n%m)
        {
            cout<<n<<endl;
        }
        else{
            int na=n, ma=m;
            ll ans=10000000000000;
            for(int j=0; j<prim.size(); j++){
                ll i=prim[j];
                int cou=0, cou2=0;
                while(na%i==0)
                {
                    na/=i;
                    cou++;
                }
               // pn[i]=cou;

                while(ma%i==0)
                {
                    ma/=i;
                    cou2++;
                }
                //pm[i]=cou2;
//                if(cou>0)
//                    db(cou);
//                if(cou2)
//                    db(cou2);

                ll po=cou-cou2+1;
                ll power=pow(i,po);
                ans=min(ans, power);
            }

            cout<<n/ans<<endl;



//            for(int i=1; i<=sqrt(m); i++)
//            {
//                if(m%i==0)
//                {
//                    d.push_back(i);
//                    d.push_back(m/i);
//                }
//            }
//            x=n/m;
//            for(int i=1; i<=sqrt(x); i++)
//            {
//                if(x%i==0)
//                {
//                    d.push_back(i);
//                    d.push_back(x/i);
//                }
//            }
//
//            sort(d.begin(), d.end());
//            ll ans=0;
//            for(int i=0; i<d.size(); i++)
//            {
//
//                y=n/d[i];
//                if(n%d[i]==0)
//                {
//                    if(y%m!=0)
//                    {
//                        ans=max(ans,y);
//                    }
//                }
//            }
//            cout<<ans<<endl;

        }


        }
    return 0;
}
