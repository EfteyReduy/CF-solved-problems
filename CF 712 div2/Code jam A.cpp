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
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pair :: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/

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
    string a="", b="";

    for(int cas=1; cas<=t; cas++)
    {
        int n;
        cin>>n;
        string s[n];
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
        }
        int ans=0;
        for(int i=1; i<n; i++)
        {
            if(s[i].length()>s[i-1].length())
                continue;

            bool grater=false, equl=true;
            for(int j=0; j<s[i].length(); j++)
            {
                if(s[i][j]==s[i-1][j])
                    continue;
                if(s[i][j]>s[i-1][j])
                {
                    //cout<<"here at i= "<<i<<endl;
                    grater=true;
                    equl=false;
                    break;
                }
                else{
                    equl=false;
                    break;
                }
            }
            if(!equl)
            {
                while(s[i].length()<s[i-1].length())
                {
                    ans++;
                    s[i]+="0";
                }
                if(!grater)
                {
                    s[i]+="0";
                    ans++;
                }
            }
            else{
                //cout<<"HERE at i= "<<i<<"and s[i] = "<<s[i]<<"and s[i-1]="<<s[i-1]<<endl;
                a=s[i];
                b=s[i-1];
                s[i]=s[i-1];
                bool al9=true;
                ans+=(b.length()-a.length());
                for(int k=s[i-1].length()-1; k>=a.length(); k--)
                {
                    //ans++;
                    if(s[i][k]=='9')
                    {
                        s[i][k]='0';
                        continue;
                    }
                    else{
                        al9=false;
                        int dig=s[i][k]-'0';
                        dig++;
                        char cc='0';
                        cc+=dig;
                        s[i][k]=cc;
                        break;
                    }
                }
                if(al9)
                {
                    ans++;
                    s[i]+="0";
                }
            }
        }

        cout<<"Case #"<<cas<<": ";
        cout<<ans<<endl;
    }

}




