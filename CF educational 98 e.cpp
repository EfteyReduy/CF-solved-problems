#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m, k;
    cin>>n>>m>>k;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int l, r;
        cin>>l>>r;
        arr[l]++;
        arr[r]--;
    }
    for(int i=1; i<n; i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }

    int cum[(n-k+1)];
    cum[0]=0;
    for(int i=0; i<k; i++)
    {
        cum[0]+=arr[i];
    }
    int j=1;
    for(int i=k; i<n; i++)
    {
        cum[j]=cum[j-1]+arr[i]-arr[j-1];
        j++;
    }

    for(int i=0; i<j; i++)
    {

    }

}
