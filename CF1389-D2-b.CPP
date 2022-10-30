#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, z;
        cin>>n>>m>>z;

        int arr[n], j=0, ans=0;
        for(int i=0; i<n+1; i++)
        {
            cin>>arr[i];
            if(i<m)
            {
                ans+=arr[i];
            }
        }
        sort(arr, arr+m);
        for(j=m-1; j>=0&&z; j--)
        {
            ans=ans+arr[j];
        }
        cout<<ans<<endl;
    }
}
