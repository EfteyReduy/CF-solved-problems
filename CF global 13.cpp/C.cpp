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



main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        ll temp=0, ans=0;
        ll flag[n], flo[n], fall[n];
        for(int i=0; i<n; i++)
        {
            fall[i]=0;
            flo[i]=0;
            flag[i]=0;
        }
        for(int i=0; i<n; i++)
        {
            ll x=arr[i];
            if(x+i+1>n)
            {
                ans+=(x+i+1-n);
                arr[i]=x-(x+1+i-n);
            }
        }
        cout<<ans<<endl;
        for(ll i=0; i<n; i++)
        {
            temp+=flag[i];
            if(arr[i]==1)
            {
                temp+=flo[i];
                continue;
            }
            ll x=arr[i]-temp-1;
            if(x>0)
                ans+=x;

            if(i+2<n)
            {
               // if(flo[i+arr[i]]<0)
                flag[i+2]++;
                fall[i+arr[i]]++;
                if(i+arr[i]<n and fall[i]+arr[i]==1)
                    flo[i+arr[i]]--;
                else{

                }
            }
            temp+=flo[i];

        }
        cout<<ans<<endl;
    }
    return 0;
}



