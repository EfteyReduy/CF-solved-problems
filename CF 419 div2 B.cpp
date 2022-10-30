#include<bits/stdc++.h>

using namespace std;


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, q, mex=200002;
    cin>>n>>k>>q;

    int arr[mex];
    memset(arr, 0, sizeof(arr));

    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        if(a>b)
            swap(a, b);
        arr[a]++;
        arr[b+1]--;
    }

    for(int i=1; i<mex; i++)
    {
        arr[i]+=arr[i-1];
    }

    for(int i=0; i<mex; i++)
    {
        if(arr[i]>=k)
        {
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }

    for(int i=1; i<mex; i++)
    {
        arr[i]+=arr[i-1];
    }

    for(int i=0; i<q; i++)
    {
        int a, b;
        cin>>a>>b;

        cout<<arr[b]-arr[a-1]<<endl;

    }

}
