#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    int arr[t];
    for(int i=0; i<t; i++)
    {
        cin>>arr[i];
    }
    int n=t, ans=0;
    bool f=false;
    for(int i=1; i<n; i++)
    {
        if(arr[i]>arr[i-1] or i==n-1)
        {
            ans++;
        }

    }
    cout<<ans<<endl;

    return 0;
}
