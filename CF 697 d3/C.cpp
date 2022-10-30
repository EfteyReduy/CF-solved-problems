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
/**

..........................for priority queue reference.........................

https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/?ref=rp

**/

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll a, b, k;
        cin>>a>>b>>k;
        ll arr[k]={0}, brr[k]={0};
        map<ll, ll>ca, cb;
        for(int i=0; i<k; i++)
        {
            ll x;
            cin>>x;
            arr[i]=x;
            ca[x]++;
        }
        for(int i=0; i<k; i++)
        {
            ll y;

            cin>>y;
            brr[i]=y;
            cb[y]++;
        }
        ll ans=0;
        for(int i=0; i<k; i++)
        {
            ll x=arr[i], y=brr[i];
            ans+=(k-(ca[x]+cb[y]-1));
        }

        cout<<ans/2<<endl;
    }
    return 0;
}


