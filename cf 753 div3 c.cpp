#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
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
        sort(arr, arr+n);

        int ans=arr[0];
        for(int i=1; i<n; i++)
        {
            ans=max(ans, arr[i]-arr[i-1]);
        }
        cout<<ans<<endl;
    }
}
