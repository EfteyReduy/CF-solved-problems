
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

bool desc(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

main()
{
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

        int i, j=n-1;
        for(i=0;i<n-1; i++)
        {
            if(arr[i]<arr[i+1])
                break;
        }
        for( ; j>0; j--)
        {
            if(arr[j]<arr[j-1])
                break;
        }

        ll dif=0, men=arr[i];
        i++;
        while(i<=j)
        {
            men=min(men, arr[i]);
            dif=max(dif, abs(arr[i]-arr[i-1]));
            i++;
        }

        if(dif>men)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }


    }

    return 0;
}

