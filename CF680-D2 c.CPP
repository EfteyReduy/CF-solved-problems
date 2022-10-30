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
    int t;
    cin>>t;
    while(t--)
    {
        ll n, m, x, y;
        cin>>n>>m;

        vector<ll>d;

        if(n%m)
        {
            cout<<n<<endl;
        }
        else{
            ll na=n, ma=m;
            while(na%m==0)
            {
                na/=m;
            }
            ll ans=na;
            na=n;

            ll cou, cou2;
            for(int i=2; i<=sqrt(m); i++)
            {
                int co=0, co2=0;
                na=n, ma=m;
                if(ma%i==0){
                    while(na%ma==0 and na>0)
                    {
                        na=na/i;
                        co++;
                    }
                    ans=max(ans, na);
                    na=n;
                    while(na%ma==0)
                    {
                        na=na/(ma/i);
                    }
                    ans=max(ans, na);
                }

            }
            cout<<ans<<endl;

        }

    }
    return 0;
}

