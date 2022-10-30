#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n], j, i, c=1, ans=0;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        if(ans<arr[i])
            ans=arr[i];
    }
    cout<<ans<<endl;
}
