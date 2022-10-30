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

ll mod=1e9+7;




void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

/// Siv's algorithm  ==================================================================================
///====================================================================================================
bool status[1000002];
map<int, bool>is_prime;
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

void setDif(){
    siv(1000000);
    for(int i=2; i<1000000 ; i++)
    {
        if(status[i]==0)
        {
            is_prime[i]=1;
        }
    }
}




void NO(){
    cout<<"NO"<<"\n";
}
void YES(){
    cout<<"YES"<<"\n";
}
void No(){
    cout<<"No"<<"\n";
}
void Yes(){
    cout<<"Yes"<<"\n";
}
void ces(int cas)
{
    cout<<"Case "<<cas<<": ";
}


main()
{
    fastIO();
    setDif();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n, e;
        cin>>n>>e;
        ll arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }


        ll ans=0;
        vector<ll>vec[e];
        for(int i=0; i<n; i++)
        {
            vec[i%e].push_back(arr[i]);
        }

        for(int i=0; i<e; i++)
        {
            vector<ll>vc=vec[i];
            ll cou=0;

            for(int j=0; j<vc.size(); j++)
            {
                if(vc[j]==1)
                {
                    cou++;
                }
                else if(is_prime[vc[j]])
                {
                    ll cnt=0;
                    while(j+1<vc.size() and vc[j+1]==1)
                    {
                        cnt++;
                        j++;
                    }
                    ans+=((cou+1)*(cnt+1))-1;
                    //cout<<"Hare at i = "<<i<<" cou = "<<cou<<" cnt = "<<cnt<<" and ans = "<<ans<<endl;
                    cou=cnt;
                }
                else{
                    cou=0;
                }

            }

        }


        cout<<ans<<endl;

    }

    return 0;
}





