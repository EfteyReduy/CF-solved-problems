#include<bits/stdc++.h>

using namespace std;
main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    long long ar[n-k+1];
    int i, j;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    ar[0]=0;
    for(i=0; i<k; i++)
    {
        ar[0]=ar[0]+arr[i];
    }
    j=1;
    for(i=k;  i<n; i++)
    {
        ar[j]=ar[j-1]-arr[j-1]+arr[i];
        j++;

    }
    long long ans=ar[0], ind;
    for(i=0; i<n-k+1; i++)
    {
        if(ar[i]<=ans)
        {
            ans=ar[i];
            ind=i;
        }
    }
    cout<<ind+1<<endl;


}
