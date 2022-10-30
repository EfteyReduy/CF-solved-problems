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

int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
        {
            return x;
        }
    }
}



main()
{
    fastIO();

    int t=1;
    //cin>>t;
    while(t--)
    {
        long long ans=1, n, m, a, b, x, y, i, j, mod=998244353;
        x= modInverse(2,998244353);
        cin>>n;
        for(i=0; i<n; i++)
        {
            ans=(ans*x)%mod;
        }

        long long cou=1;
        long long fib[n];
        fib[0]=1;
        fib[1]=1;
        for(int i=2; i<n; i++)
        {
            fib[i]=fib[i-1]+fib[i-2];
            fib[i]%=mod;
        }

        ans=(ans*fib[n-1])%mod;
        cout<<ans<<endl;


    }

}
