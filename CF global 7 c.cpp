#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod=998244353;

int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    ll ans=1;
    int i=0;
    while(arr[i]<n-k+1 and i<n)
    {
        i++;
    }
    int j=n-1;
    while(arr[j]<n-k+1 and j>0)
    {
        j--;
    }
    ll temp=0, cou=1;

    while(i<=j)
    {
        if(arr[i]<n-k+1)
        {
            cou++;
            //ans+=temp;
        }
        else{
            ans=ans*cou;
            ans%=mod;
            cou=1;
        }
        i++;
    }
    for(int i=0; i<k; i++)
    {
        temp+=n;
        n--;
    }
    cout<<temp<<" ";
    cout<<ans<<endl;
}
