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

long long ncr(long long n, long long r)
{
    if(n<r)
        return 0;
    if(n==r)
        return 1;

    long long ans=1, x=max(r, (n-r));
    x++;

    for(int i=1; x<=n; x++,i++)
    {
        ans=ans*x;
        ans=ans/i;
    }
    return ans;
}


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        long long  n;
        cin>>n;
        long long arr[n]={0};

        map<long long, long long >mp;
        for(int i=0; i<n; i++)
        {
            long long a;
            cin>>a;
            arr[a]++;
            mp[a]++;
        }
        long long ans=0;
        bool bb=false;
        for(auto i :mp)
        {
            long long x=i.second, sec=0, thi=0;
            if(mp.find(i.first+1)!=mp.end())
            {
                sec=mp[i.first+1];
            }
            if(mp.find(i.first+2)!=mp.end())
            {
                thi=mp[i.first+2];
            }
            ans+=ncr((x+sec+thi),3);
           // ans-=ncr(x,3)-ncr((x+sec),3)-ncr((x+thi),3)
           if(sec and thi)
                ans=ans-ncr((thi+sec),3);
            ans=ans-ncr(sec,3)-ncr(thi,3);
        }
        cout<<ans<<endl;
    }
}


