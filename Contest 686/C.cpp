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



typedef long long ll;
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pair :: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        //map<int, int>mp;
        vector<int>v[n+1];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            v[arr[i]].push_back(i);
            //mp[arr[i]]++;
        }
        int ans=1e9;
        for(int i=1; i<=n; i++)
        {
            if(v[i].size()==0)
                continue;

            int temp=1, pre=v[i][0];
            if(v[i][0]==0)
            {
                temp--;
            }
            int j=1;
            for(j=1; j<v[i].size(); j++)
            {
                //cout<<"here without problem.."<<endl;
                int dif=v[i][j]-pre;
                pre=v[i][j];
                if(dif>1)
                    temp++;

            }
           // cout<<"Did i came here??"<<endl;
            if(v[i][(v[i].size()-1)]!=(n-1))
            {
               // cout<<"Is this the problem!!!"<<endl;
                temp++;
            }
            ans=min(ans,temp);
        }
        cout<<ans<<endl;

    }
}




