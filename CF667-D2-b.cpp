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

using namespace std;

//#define SSA(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});//sorting array of string in ascending order
//#define SSD(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() > b.size();});//sorting array of string in descending order



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
        ll a, b, x, y, n;
        cin>>a>>b>>x>>y>>n;
        int mi, ma;
        if(a>b)
        {
            swap(a,b);
            swap(x,y);
        }
        if(a==b)
        {
            mi=min(x,y);
            x=mi;
            y=max(x,y);
        }
        int s=a;

        if(1)
        {
            if(a-n<x)
            {
                n=n-a+x;
                a=x;

                if(b-n<y)
                {
                    b=y;

                }
                else{
                    b=b-n;
                }
            }
            else
            {
                a=a-n;
                n=0;
            }
        }
        ll ans=a*b;
        if(b<a and b>y)
        {
            int po=b-y, p=s-a;
            int s=min(po, p);
            a=a+s;
            b=b-s;
        }
        ans=min(ans,a*b);
        cout<<ans<<endl;
    }
    return 0;
}

