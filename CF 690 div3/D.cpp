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


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n], sum=0, mex=0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]>mex)
                mex=arr[i];
            sum+=arr[i];
        }
        vector<long long> pos;
        for(int i=1; i*i<=sum; i++)
        {
            if(sum%i==0)
            {
                pos.push_back(i);
                pos.push_back(sum/i);
            }
        }

        sort(pos.begin(), pos.end());
        long long ans=0;
        for(auto i:pos)
        {
            if(i<mex)
            {
                continue;
            }
            bool impossible=false;
            long long temp=0;
            for(int j=0; j<n; j++)
            {
                if(temp<i)
                    temp+=arr[j];
                if(temp==i)
                {
                    temp=0;
                }
                else if(temp>i)
                {
                    impossible=true;
                    break;
                }
            }
            if(!impossible)
            {
                ans=i;
                break;
            }
        }

        cout<<(n-(sum/ans))<<endl;


    }
}

