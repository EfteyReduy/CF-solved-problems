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
main()
{
    fastIO();

    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int brr[n];
        map<long long, long long> mp;
        for(int i=0; i<n; i++)
        {
            cin>>brr[i];
            mp[brr[i]]++;
        }
        bool ans=false;
        for(auto i:mp)
        {
            if(i.second>1)
                {
                    ans=true;
                    break;
        }
        }
        if(ans)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }

    }
}




