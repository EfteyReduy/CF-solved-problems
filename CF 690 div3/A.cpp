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
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n/2; i++)
        {
//            if(i%2==0)
//            {
//                cout<<arr[i]<< " ";
//            }
            cout<<arr[i]<<" "<<arr[n-i-1]<< " ";
        }
        if(n%2)
        {
            cout<<arr[n/2];
        }
//        for(int i=n-1; i>0; i--)
//        {
//            if(i%2)
//            {
//                cout<<arr[i]<<" ";
//            }
//        }
        cout<<endl;
    }
}
