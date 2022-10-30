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

#define mod 1000000007
#define precision(x) cout<<fixed<<setprecision(x);
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//typedef long long ll;
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
// Returns factorial of n
ll fact(ll n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = (res * i)%mod;
    return res%mod;
}


ll nPr(ll n, ll r)
{
    return (fact(n) /fact(n - r));
}






main()
{
    //Start code from here........
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll n, x, pos;
        cin>>n>>x>>pos;

        ll les=0, great=0;

        ll lo=0, hi=n-1, cou=0;

        while(lo<=hi)
        {
            cou++;
            int mid=(lo+hi)/2;
            if(mid==pos)
                break;
            else if(pos>mid)
            {
                les++;
                lo=mid+1;
            }
            else{
                les++;
                hi=mid;
            }

        }

        db(les);
        db(great);

        ll b=x-1, p=1, q=1;
        ll a=n-x+1;
        db(a);
        db(b);
       // db((fact(a)));
        p=fact(a)/fact(a-great);
        for(int i=a; i>a-great; i--)
        {
            p=(p*i)%mod;
        }
        for(int i=b; i>b-les; i--)
        {
            q=(q*i)%mod;
        }

        //q=fact(b)/fact(b-les);

        db(p);
        db(q);
//
//        for(int i=1; i<great; i++)
//        {
//            p=(p*a)%mod;
//
//        }
//        for(int i=0; i<les; i++)
//        {
//            q=(q*b)%mod;
//        }


        long long ans=1;
        ans=(ans*p)%mod;
        ans=(ans*q)%mod;
        for(int i=1; i<=n-cou; i++)
        {
            ans=(ans*i)%mod;
        }


        cout<<ans%mod<<endl;


    }



    return 0;
}


/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 🙁 )
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing 😕
*/


/**
 * Use pen and paper. Solve on paper then code.
 * If there is some reasoning e.g. sequence/paths, try printing first 100 elements or 100 answers using brute and observe.
 * Read question with extreme caution. Sometimes we make question complex due to misunderstanding.
 * Prefix sum and suffix sum is highly usable concept, look for it.
 * Think of cleanest approach. If too many if else are coming then its indication of WA.
**/

