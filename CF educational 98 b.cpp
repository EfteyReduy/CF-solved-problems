#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long total=0, arr[n], mex=0, idx;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]>mex)
                mex=arr[i], idx=i;
        }
        for(int i=0; i<n; i++)
        {
            total+=abs(arr[i]-mex);
        }
        if(n==2 or mex==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(total)
            cout<<abs(total-mex)<<endl;
        else{
            long long a=mex%(n-1);
            if(a)
                cout<<(n-1-a)<<endl;
            else{
                cout<<0<<endl;
            }
        }

    }
}
