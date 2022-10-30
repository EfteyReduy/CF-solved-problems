#include<bits/stdc++.h>
using namespace std;

main()
{
    int n, a;
    cin>>n>>a;
    int arr[n],b , j, i, c=0, ans=0;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    if(arr[a-1]==1)
        ans++;
    i=1;
    while(1)
    {
        if(a-i-1<0||a+i-1>=n)
        {

            break;
        }

        if(arr[a-i-1]==1 && arr[a+i-1]==1)
        {
            ans=ans+2;
        }

        i++;
    }
    for(j=a+i-1; j<n; j++)
    {
        if(arr[j]>0)
            ans++;
    }
    for(j=a-i-1; j>=0; j--)
    {
        if(arr[j]>0)
            ans++;
    }

    cout<<ans<<endl;
}
