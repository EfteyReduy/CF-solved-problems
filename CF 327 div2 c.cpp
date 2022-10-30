#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
//    arr[0]=arr[1];
//    arr[n+1]=arr[n];
//

    int ans=0;
    for(int i=1; i<n; i++)
    {
        int j=i, cou=0;

        while(j<n and arr[j]!=arr[j-1])
        {
            j++;
            cou++;
        }
        ans=max(ans, cou/2);
        for(int k=i; k<i+((j-i)/2); k++)
        {
            arr[k]=arr[i-1];
        }
        for(int k=i+((j-i)/2); k<j; k++)
        {
            arr[k]=arr[j-1];
        }
        i=j;
    }
    cout<<ans<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
