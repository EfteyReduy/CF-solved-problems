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
///==================================================================================================

#define SSA(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});//sorting array of string in ascending order
#define SSD(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() > b.size();});//sorting array of string in descending order



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
main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        string s;
        cin>>s;
        int x=a, y=b;
        bool pos=true;
        if(a%2 and b%2)
        {
            //cout<<"HERE"<<endl;
            pos=false;
        }
        int n=s.length();
        for(int i=0; i<n/2; i++)
        {
            if(s[i]==s[n-i-1])
            {
                continue;
            }
            if(s[i]=='0')
            {
                if(s[n-i-1]=='?')
                {
                    s[n-i-1]='0';
                }
                else{
                    pos=false;
                    break;
                }
            }
            else if(s[i]=='1')
            {
                if(s[n-i-1]=='?')
                {
                    s[n-i-1]='1';
                }
                else{
                    pos=false;
                    break;
                }
            }
            else{
                if(s[n-i-1]=='0')
                {
                    s[i]='0';
                }
                else{
                    s[i]='1';
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(s[i]=='0')
            {
                a--;
            }
            else if(s[i]=='1')
            {
                b--;
            }
        }
        if(a<0 or b<0)
        {
            pos=false;
        }
        for(int i=0; i<n/2; i++)
        {
            if(s[i]=='?')
            {
                if(s[n-1-i]=='?')
                {
                    if(a>=2)
                    {
                        s[i]='0';
                        s[n-i-1]='0';
                        a-=2;
                    }
                    else if(b>=2)
                    {
                        s[i]='1';
                        s[n-i-1]='1';
                        b-=2;
                    }
                }

            }
        }
        if(n%2)
        {
            if(s[n/2]=='?')
            {
                if(a>0)
                {
                    s[n/2]='0';
                }
                else if(b>0)
                {
                    s[n/2]='1';
                }
            }
        }
        int one=0, zero=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='1')
            {
                one++;
            }
            else{
                zero++;
            }
        }
        if(one==y and zero==x and pos)
        {
            cout<<s<<endl;
        }
        else{
                //cout<<s<<endl;
            cout<<-1<<endl;
        }
    }
}

