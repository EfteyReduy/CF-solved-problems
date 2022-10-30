#include<bits/stdc++.h>

using namespace std;


main()
{
    int n, j, k, mex=0, mex2=0;
    cin>>n;
    int arr[n]={0};
    long long tot=0, ans=0;
    int an[n]={0};
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]>mex)
            j=i;
        mex=max(arr[i], mex);
        tot=tot+arr[i];

    }
    for(int i=0; i<n; i++)
    {
        if(i!=j)
        {
            if(arr[i]>mex2)
                k=i;
            mex2=max(mex2,arr[i]);

        }
    }

    for(int i=0; i<n; i++)
    {
        if(i!=j)
        {
            if(tot-arr[i]-arr[j]==arr[j])
            {
                an[ans]=i;
                ans++;
            }
        }
        else
        {
            if(tot-arr[i]-arr[k]==arr[k])
            {
                an[ans]=i;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=0; i<ans; i++)
    {
        cout<<an[i]+1<<" ";
    }
    cout<<endl;
}
