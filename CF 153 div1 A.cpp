#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    int n, d;
    cin>>n>>d;
    ll arr[n+1];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    arr[n]=1e10;
    ll a, b, i, j, ans=0;
    a=b=i=j=0;
    while(i<n-1)
    {
        if(abs(arr[j]-arr[i])>d)
        {
            a=j-i-1;

            b=max((ll)0, a*(a-1)/2);
            ans+=b;
            i++;
        }
        else{
            j++;
        }
    }
    cout<<ans<<endl;

}
