#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n);

    int i=0, j=n-1, ans=0;
    while(i<=j)
    {
        if(arr[i]+arr[j]<=x)
        {
            ans++;
            i++;
            j--;
        }
        else{
            ans++;
            j--;
        }
    }
    cout<<ans<<endl;

}
