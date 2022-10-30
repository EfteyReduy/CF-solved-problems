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
void ces(int cas)
{
    cout<<"Case "<<cas<<": ";
}

int quer(int a, int b, int c, int d)
{
    int x;
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout.flush();
    cin>>x;
    return x;
}

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x, y;
        int i=2;
        int ans[n+1];

        int a, b, c, d;
        a=quer(1, 1, 2, n-1);
        b=quer(2, 1, 2, 1);

        c=quer(1, 3, 2, n-1);
        d=quer(2, 3, 2, 1);

        if(a==c)
        {
            ans[2]=a;
            ans[i-1]=b;
            ans[i+1]=d;
        }
        else if(a==d)
        {
            ans[i]=a;
            ans[i-1]=b;
            ans[i+1]=c;
        }
        else if(b==c)
        {
            ans[i]=b;
            ans[i-1]=a;
            ans[i+1]=d;
        }
        else if(b==d)
        {
            ans[i]=b;
            ans[i-1]=a;
            ans[i+1]=c;
        }


        if(n%3==1)
        {
            i+=1;
        }
        else if(n%3==2)
        {
            i+=2;
        }
        for(  ; i<n; i+=3)
        {
            int a, b, c, d;
           // cout<<"HERE"<<endl;
            a=quer(1, i, i-1, n-1);
            b=quer(2, i, i-1, 1);

            c=quer(1, i, i+1, n-1);
            d=quer(2, i, i+1, 1);

            if(a==c)
            {
                ans[i]=a;
                ans[i-1]=b;
                ans[i+1]=d;
            }
            else if(a==d)
            {
                ans[i]=a;
                ans[i-1]=b;
                ans[i+1]=c;
            }
            else if(b==c)
            {
                ans[i]=b;
                ans[i-1]=a;
                ans[i+1]=d;
            }
            else if(b==d)
            {
                ans[i]=b;
                ans[i-1]=a;
                ans[i+1]=c;
            }

        }
        cout<<"! ";
        for(int i=1; i<=n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;


    }

    return 0;
}



