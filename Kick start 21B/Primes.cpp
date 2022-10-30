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



/// Siv's algorithm  ==================================================================================
///====================================================================================================
bool status[100000];
vector<ll>pri;
ll diff[100000];

void siv(int N) {
    ll sq = sqrt(N);

    for (int i = 4; i <= N; i += 2) {
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
    for(int i=2; i<100000; i++)
    {
        if(status[i]==0)
        {
            diff[j]=i;
            j++;
            pri.push_back(i);
        }
    }
}
///==================================================================================================

#define SSA(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});//sorting array of string in ascending order
#define SSD(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() > b.size();});//sorting array of string in descending order



typedef long long ll;


void cas(int i)
{
    cout<<"Case #"<<i<<": ";
}



main()
{
    fastIO();
    int t=1;
    //int zzz=sqrt(1000000000);
    siv(100000);
    setDif();
    cin>>t;
    for(int xx=1; xx<=t; xx++)
    {
        ll z;
        cin>>z;
        ll c, a, b;
        ll sq=sqrt(z);


        for(ll i=sq+1;  ; i++)
        {
            bool pos=true;
            for(ll j=0; pri[j]*pri[j]<=i; j++)
            {
                if(i%pri[j]==0)
                {
                    pos=false;
                    break;
                }
            }
            if(pos)
            {
                c=i;
                break;
            }
        }

        for(ll i=sq; i>1; i--)
        {
            bool pos=true;
            for(ll j=0; pri[j]*pri[j]<=i and j<pri.size(); j++)
            {
                if(i%pri[j]==0)
                {
                    pos=false;
                    break;
                }
            }
            if(pos)
            {
                b=i;
                break;
            }
        }
        cas(xx);
        if(b*c<=z)
        {
            cout<<b*c<<endl;
            continue;
        }
        for(ll i=b-1; i>0; i--)
        {
            bool pos=true;
            for(ll j=0; pri[j]*pri[j]<=i; j++)
            {
                if(i%pri[j]==0)
                {
                    pos=false;
                    break;
                }
            }
            if(pos)
            {
                a=i;
                break;
            }
        }
        cout<<a*b<<endl;


    }
    return 0;
}


