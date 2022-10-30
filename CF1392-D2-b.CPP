#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n>>k;
        int arr[n], mex=-1e9+1, men=1e9+1;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]>mex)
            {
                mex=arr[i];
            }
            if(arr[i]<men)
            {
                men=arr[i];
            }
        }
        if(men!=0){
            for(int i=0; i<n; i++)
            {
                arr[i]=mex-arr[i];
            }
            k--;
            mex=mex-men;

        }
        if(k%2!=0)
        {
            for(int i=0; i<n; i++)
            {
                cout<<mex-arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int i=0; i<n; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
}
