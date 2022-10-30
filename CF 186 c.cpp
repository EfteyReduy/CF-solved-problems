#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
bool desc(const ll &a, const ll &b)
{
    return a>b;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n,desc);
    for(int i=1; i<n; i++)
    {
        arr[i]+=arr[i-1];
    }
    ll cou=1, ans=0;
    while(n>0)
    {
        ans+=arr[n-1];
        n=n/4;
        cou++;
    }
    cout<<ans<<endl;
}
