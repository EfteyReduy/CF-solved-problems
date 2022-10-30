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


// function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll * x, ll * y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

ll modInverse(ll a, ll m)
{
	ll x, y;
	ll g = gcdExtended(a, m, &x, &y);
	if (g != 1)
        return -1;
		//printf("Inverse doesn't exist");
	else
	{
		ll res = (x % m + m) % m;
		//printf("Modular multiplicative inverse is %d", res);
		return res;
	}
}


void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/// Siv's algorithm  ==================================================================================
///====================================================================================================
bool status[40000];
int dif[100000]={0};

vector<ll>prim;
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
    int j=0;
    for(int i=2; i<31623; i++)
    {
        if(status[i]==0)
        {
            prim.push_back(i);
            dif[j]=(i);
            j++;
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

priority_queue<pair<int, int >>pq;

main()
{
    siv(31623);
    setDif();

    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll a, b, c, k;
        cin>>a>>b>>k;
        if(a>b)
            swap(a,b);
        ll x=a, y=b;
        //ll x=__gcd(a,b);
        ll cou=0;
        vector<ll>diva, divb;
        for(int i=0; i<prim.size(); i++)
        {
            while(a%prim[i]==0)
            {
                a/=prim[i];
                cou++;
                diva.push_back(prim[i]);
            }
            while(b%prim[i]==0)
            {
                b/=prim[i];
                cou++;
                divb.push_back(prim[i]);
            }
            if(a<prim[i] and b<prim[i])
            {
                break;
            }
        }
        if(a>1)
        {
            cou++;
        }
        if(b>1)
        {
            cou++;
        }
        if(k==cou)
        {
            YES();
        }
        else if(k<cou)
        {
            if(k==1)
            {
                if(y==x)
                {
                    NO();
                }
                else if(y%x)
                {
                    No();
                }
                else{
                    YES();
                }
            }
            else{
                YES();
            }
        }
        else{
            NO();
        }

    }
    return 0;
}


