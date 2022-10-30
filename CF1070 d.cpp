#include<bits/stdc++.h>

using namespace std;

main()
{
    long long t;
    t=1;
    while(t--)
    {
        long long n, k;
        cin>>n>>k;

        long long arr[n], pre=0, ans=0, npre=0;

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            arr[i]+=pre;
            ans+=(arr[i]/k);
            npre=arr[i]%k;
            if(arr[i]==npre and pre!=0)
            {
                //cout<<"here at i = "<<i<<endl;
                pre=0;
                ans++;
                npre=0;
            }
            pre=npre;
        }
        if(pre)
            ans++;
        cout<<ans<<endl;

    }
}
