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
int gcdExtended(ll a, ll b, ll* x, ll* y)
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


///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
}/**


**/

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s.length()<=2)
        {
            if(s.length()==2)
            {
                if(s[0]==s[1])
                {
                    cout<<1<<endl;
                    continue;
                }
                else
                {
                    cout<<0<<endl;
                    continue;
                }
            }
            else{
                cout<<0<<endl;
                continue;
            }
        }
        int cou=0;
        if(s[0]==s[1])
        {
            cou++;
            s[1]='4';
        }
        for(int i=2; i<s.length(); i++)
        {
            if(s[i]==s[i-1] or s[i]==s[i-2])
            {
                bool s2=false, s1=false;
                if(s[i]==s[i-2])
                {
                    cou++;
                    s2=true;
                }
                if(s[i]==s[i-1])
                {
                    cou++;
                    s1=true;
                }
                if(s2)
                {
                    s[i]='2';
                }
                if(s1)
                {
                    s[i]='0';
                }
                if(s1 and s2)
                {
                    s[i-1]='1';
                }
            }
        }
        //cout<<s<<endl;

        cout<<cou<<endl;

    }

    return 0;
}




