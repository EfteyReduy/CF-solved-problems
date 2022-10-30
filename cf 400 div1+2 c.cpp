#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

main()
{
    ll n, k;
    cin>>n>>k;

    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    ll cum[n];
    cum[0]=arr[0];
    map<ll, ll>mp;
    mp[arr[0]]++;
    for(int i=1; i<n; i++)
    {
        cum[i]=cum[i-1]+arr[i];
        mp[cum[i]]++;
    }

    ll ans=0, prev=0;
    for(int i=0; i<n; i++)
    {
        ll val=1;
        while(val<=1e15)
        {

        }

        prev=arr[i];
    }

}
