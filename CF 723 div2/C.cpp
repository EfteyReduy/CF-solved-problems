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

main()
{
    fastIO();
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        vector<pair<int, int> >vc, po;
        vector<int>p;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]<0)
            {
                vc.push_back({-arr[i], i});
            }
            else{
                po.push_back({arr[i], i});
            }
        }
        //db(vc.size());
        sort(vc.begin(), vc.end());
        int point=0;
        ll cum[n];
        cum[0]=max(0, arr[0]);
        for(int i=1; i<n; i++)
        {
            if(arr[i]>0)
            {
                cum[i]=cum[i-1]+arr[i];
            }
            else{
                cum[i]=cum[i-1];
            }
        }
        arr[0]=max(arr[0], 0);
        int extra=cum[0], cou=0;
        for(int i=0; i<vc.size(); i++)
        {
            if(vc[i].first>(cum[vc[i].second]-cum[point]+arr[point]))
            {
                cou++;
                continue;

            }
            vc[i].first-=extra;
            extra=0;
            for(int j=point; j<vc[i].second; j++)
            {
                if(arr[j]<0)
                    continue;
                if(arr[j]<vc[i].first)
                {
                    vc[i].first-=arr[j];
                }
                else{
                    db(j);
                    db(point);
                    db(arr[j]);
                    db(vc[i].first);
                    extra=arr[j]-vc[i].first;
                    point=j;
                    break;
                }
            }

        }
        cout<<n-cou<<endl;
    }
    return 0;
}


