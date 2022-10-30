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
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        int brr[n];
        memset(brr, 0, sizeof(brr));

        int lo=0, hi=1e9+3, ans=0;
        while(lo<=hi)
        {
            bool pos=true;
            int mid=(lo+hi)/2;
            for(int i=n-1; i>1; i--)
            {
                if(arr[i]+brr[i]<mid)
                {
                    pos=false;
                    break;
                }
                else{
                    int rem=min(arr[i], arr[i]+brr[i]-mid);
                    int d=rem/3;
                    brr[i-1]+=d;
                    brr[i-2]+=(2*d);
                }
            }
            if(arr[0]+brr[0]<mid or brr[1]+arr[1]<mid)
            {
                pos=false;
            }

            if(pos)
            {
                ans=max(ans, mid);
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            memset(brr, 0, sizeof(brr));
        }
        cout<<ans<<endl;
    }
}
