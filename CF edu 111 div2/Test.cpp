
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
bool status[400000];
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

void setDif(){
    int j=0;
    for(int i=2; i<400000 ; i++)
    {
        if(status[i]==0)
        {
            dif[j]=(i);
            j++;
        }
    }
}

///comparison structure to use customized set.............
struct cmpStruct {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first < rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

//set<pair<int, int>, cmpStruct> s;


///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
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


bool checkEq(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=arr[0])
        {
            return false;
        }
    }
    return true;
}
main()
{
    fastIO();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        map<ll, ll>dif, val;
        ll last=1;
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            ll x=arr[i]-i;
            if(dif[arr[i]-i] and val[arr[i]])
            {
                //cout<<"HRE"<<endl;

                if(dif[x]<val[arr[i]] and last<=dif[x])
                {
                    ans--;
                }

            }

            if(val[arr[i]])
            {
                ll y=arr[i];
                if(val[y]<last)
                {
                    val[y]=i+1;
                }
                else{
                    ll aaa=val[y]-1;
                    ans+=(i-aaa)*(aaa-last+1);
                    ans+=(aaa-last+1+2)*(aaa-last+1+1)/2;
                    last=val[y]+1;
                    val[y]=i+1;
                    db(ans);
                }

            }
            else if(dif[x])
            {
                if(dif[x]<last)
                {
                    dif[x]=i+1;
                }
                else{
                    ll aaa=dif[x]-1;
                    ans+=(i-aaa-1)*(aaa-last+2);
                    ans+=(aaa-last+2+1)*(aaa-last+1+1)/2;

                    last=max(dif[x]+1, last);
                    dif[x]=i+1;
                }
            }
            else{
                val[arr[i]]=i+1;
                dif[arr[i]-i]=i+1;
            }
        }
        for(auto it:dif)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        ans+=(n-last+2)*(n-last+1)/2;
        cout<<ans<<endl;
    }
    return 0;
}








