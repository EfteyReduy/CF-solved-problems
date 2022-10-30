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


bool status[1000001];
int dif[100000];

void siv(ll N) {
    ll sq = 1000;

    for (ll i = 4; i <= N; i += 2) {
        status[i] = 1;
    }

    for (ll i = 3; i <= sq; i += 2) {
        if (status[i] == 0) {
            for (ll j = i * i; j <= N; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}

void setDif(){
    int j=0;
    for(int i=2; i<=1000000 ; i++)
    {
        if(status[i]==0)
        {
            dif[j]=i;
            j++;
        }
    }
    //cout<<dif[j-1]<<endl;
    //cout<<j<<endl;
}




vector<ll>vec;
void nondiv(ll n) {
    for (ll i = 0; dif[i]*dif[i]<=n and i<=78497; i++) {
        if (n % dif[i] == 0) {
            while (n % dif[i] == 0)
            {
                n /= dif[i];
            }
            vec.push_back(dif[i]);
        }
    }
    if (n > 1)
    {
        vec.push_back(n);
    }
    //return vec;
}
ll n, m;
ll sum=0;


void dfs(ll idx, long long p, int cnt) {
    if(idx == m) {
        if(cnt&1)
            sum -= n/p;
        else
            sum += n/p;
        return;
    }
    if(p > n)       return;
    dfs(idx+1, p*vec[idx] , cnt+1);
    dfs(idx+1, p, cnt);
}

main()
{

    fastIO();
    siv(1000000);
    setDif();
    int t=1;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {

        ll ans, a, b, temp;
        cin>>a>>b>>temp;
        if(a>b)
            swap(a,b);
        if(a==b)
        {
            cout<<"Case "<<cas<<": ";
            if(a==1)
            {
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }

            continue;
        }
        ll x, y;
        nondiv(b-a);
        ll z=b-a;

        m=vec.size();
        n=a-1;
        dfs(0,1,0);
        x=sum;
        n=a+temp;
        sum=0;
        dfs(0,1,0);

        y=sum;
        cout<<"Case "<<cas<<": ";
        cout<<y-x<<endl;
        sum=0;
        vec.clear();
    }

    return 0;
}





