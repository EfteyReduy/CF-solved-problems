#include<bits/stdc++.h>

using namespace std;


main()
{
    long long n, k;
    cin>>n>>k;
    long long arr[n], brr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>brr[i];
    }

    long long lo=0, hi=10000000000, ans=0;
    bool t=0;
    while(lo<=hi)
    {
        long long mi=(lo+hi)/2, l=k;
        for(int i=0; i<n; i++)
        {
            long long r=brr[i]/arr[i];
            if(r<mi)
            {

                long long req=((mi-r)*arr[i])-(brr[i]-(arr[i]*r));
                l-=req;
                if(l<0)
                    break;
            }
        }
        if(l<0)
            hi=mi-1;
        else if(l==0)
        {
            ans=max(ans,mi);
            break;
        }
        else if(l>0)
        {
            lo=mi+1;
            ans=max(ans,mi);
        }
    }
    cout<<ans<<endl;
}
