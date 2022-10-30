#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n]={0};
    int ind, mex=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]*i>mex)
        {
            mex=arr[i];
            ind=i;
        }
    }
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        if(i!=ind)
        {
            ans=ans+(4*arr[i]*i);
        }
        else{
            ans=ans+(4*arr[i]*i);
        }
    }
    cout<<ans<<endl;
}
