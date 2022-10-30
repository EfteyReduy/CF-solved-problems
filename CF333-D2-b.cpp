#include<bits/stdc++.h>
#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans=0, i=0, j=0, ide, jd, low=arr[0], hi=arr[0];

    for(i=0; i<n; i++)
    {
        if(arr[i]<low)
        {
            low=arr[i];
            break;
        }
        if(arr[i]>hi)
        {
            hi=arr[i];
            break;
        }
    }
    i=0;

    for(int k=0; k<n; k++)
    {
        if(arr[k]==low)
            ide=k;

        if(arr[k]==hi)
            jd=k;

        if(arr[k]-low>1)
        {
            low=hi;
            hi=arr[k];
            ans=max(ans, (k-i));
            i=ide+1;
            ide=jd;
            jd=k;
//            cout<<"here at ";
//            db(k);
//            db(i);
        }
        else if(hi-arr[k]> 1)
        {
            hi=low;
            low=arr[k];
            ans=max(ans, (k-i));
            i=jd+1;
            jd=ide;
            ide=k;

        }
        ans=max(ans, (k-i+1));
        if(arr[k]==low)
            ide=k;

        if(arr[k]==hi)
            jd=k;

    }
    cout<<ans<<endl;

}
