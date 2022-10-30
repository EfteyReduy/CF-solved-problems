#include <bits/stdc++.h>


using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,ans=0;
        int test=0;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long m=n-1;
        for(int i=0;i<m;i++)
        {
            if(arr[i]>arr[i+1])
            {
                if(test==0)
                {
                    ans = ans + (arr[i]-arr[i+1]);
                }
            }
            else
                test=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
