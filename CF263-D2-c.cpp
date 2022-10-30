#include<bits/stdc++.h>

typedef long long ll;
using namespace std;


int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n);
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=arr[i];
    }
    for(int i=1; i<n; i++)
    {
        ans+=(arr[i-1]);
        ans+=(arr[i]*i);
    }
    cout<<ans;
    cout<<endl;
}
