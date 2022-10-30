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
bool sortrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
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
main()
{
    fastIO();

    int t=1;
    cin>>t;
    map<int, int>m;

    long long n, a=0, b=0, an=t;
    while(t--)
    {

        cin>>n;
        long long cou=0;
//        if(n==0)
//            m[1]++;
        if(1){
            while(n>0)
            {
                n=n/2;
                cou++;
            }
            m[cou]++;
        }
    }
    n=m.size();
    long long x=0;
   // cout<<" N = "<<n<<endl;
    for(auto i:m)
    {
        n=n-1;
        a=i.second;

        if(n+1<m.size())
            a++;
        n=max(n,x);
        b=max(b, a+n);
    }

    cout<< an-(b)<<endl;



}





