
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

typedef long long ll;

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




main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n, m, x;
        cin>>n>>m>>x;
        map<int, vector<ll> >mp;
        int arr[n];
        pair<ll, int>p[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            p[i].first=arr[i];
            p[i].second=i;
        }
        sort(p, p+n);

        ll sum=0, men=p[0].first, j=1;
        mp[j].push_back(p[0].second);
        for(int i=1; i<n; i++)
        {
            if(p[i].first-men<=x)
            {
                mp[j].push_back(p[i].second);
            }
            else{
                j++;
                men=p[i].first;
                mp[j].push_back(p[i].second);
            }
        }
        if(mp.size()>m)
        {
            NO();
        }
        else{
            int ans[n];
            memset(ans, -1, sizeof(ans));
            for(auto it:mp)
            {
                vector<ll>v=it.second;
                for(int i=0; i<v.size(); i++)
                {
                    ans[v[i]]=it.first;
                }
            }
            map<int, int>mm;
            for(int i=0; i<n; i++)
            {
                if(j==m)
                {
                    break;
                }
                if(mm[ans[i]])
                {
                    j++;
                    ans[i]=j;
                    mm[j]=1;
                }
                else{
                    mm[ans[i]]=1;
                }
            }
            Yes();
            for(int i=0; i<n; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }


    }

    return 0;
}


