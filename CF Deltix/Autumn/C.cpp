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
        bool vis[e];
        int ccu[e];
        memset(vis, 0, sizeof(vis));
        memset(ccu, 0, sizeof(ccu));
        int ans=0;
        for(int i=n-1; i>=0; i--)
        {
            int x=(i)%e;
            if(arr[i]>1 and !vis[x])
            {
                vis[x]=1;
                if(is_prime[arr[i]])
                {
                    //cout<<"hare at i = "<<i<<endl;
                    int idx=i-e, cou=0;
                    while(idx>=0 and arr[idx]==1)
                    {
                        cou++;
                        idx-=e;
                    }
                    if((cou>0 or ccu[x]>0) and idx<0)
                    {
                        ans++;
                    }

                }
            }
            else if(!vis[x])
            {
                ccu[x]++;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}




