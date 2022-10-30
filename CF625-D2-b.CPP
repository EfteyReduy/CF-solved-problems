#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, k, a=1;
    cin>>n>>k;

    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k-1; j++)
        {
            arr[i][j]=a;
            a++;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=k-1; j<n; j++)
        {
            arr[i][j]=a;
            a++;
        }
    }
    int ans=0;
    for(int i=0; i<n; i++)
        ans+=arr[i][k-1];
    cout<<ans<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
