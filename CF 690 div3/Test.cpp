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
    int t=1;
    cin>>t;
    while(t--)
    {
        long long  n;
        cin>>n;
        long long arr[n];

//        sort(arr, arr+n);

        map<long long, long long >mp;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            mp[arr[i]]++;
        }
        long long ans=0;
        bool bb=false;
        for(auto i :mp)
        {
//            cout<<" I = "<<i.first<<endl;
            long long x=i.second;
//            cout<<"ncr("<<x<<" ,3 )="<<ncr(x,3)<<endl;
//            ans+=ncr(x,3);
            //cout<<ans<<endl;
            if(mp.find(i.first+1)!=mp.end())
            {
                x+=mp[i.first+1];
//                if(bb)
//                    ans-=ncr(x,3);
//                else{
//                    bb=true;
//                }
//                cout<<"ncr("<<x<<" ,3 )="<<ncr(x,3)<<endl;
            }
            //cout<<ans<<endl;

            if(mp.find(i.first+2)!=mp.end())
            {
                x+=mp[i.first+2];
               // ans+=ncr(x,3);
//                cout<<"ncr("<<x<<" ,3 )="<<ncr(x,3)<<endl;
            }
            if(x>2)
            ans+=(x*(x-1))/2;
           // cout<<ans<<endl;
           // cout<<endl;
        }
        cout<<ans<<endl;

    }
}

