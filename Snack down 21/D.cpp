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
        if(n==2)
        {
            cout<<0<<endl;
            continue;
        }
        sort(arr, arr+n);

        int x=arr[0]+arr[n-1];
        x/=2;

        int strt=0, ind;

        strt=lower_bound(arr, arr+n, x)-arr;

        ind=strt-1;
        swap(strt, ind);
        int ans=2e9;
        if(strt==0)
        {
            ans=arr[n-1]-arr[1];
        }
        if(ind==n-1)
        {
            ans=arr[n-2]-arr[0];
        }

        while(strt>0 and ind<n-1)
        {
            cout<<"Strt = "<<strt<<"   ind = "<<ind<<endl;
            ans=min(ans, abs((arr[ind]-arr[0])-(arr[n-1]-arr[strt])));

            if((arr[ind]-arr[0])>(arr[n-1]-arr[strt]))
            {
                strt--;
            }
            else{
                ind++;
            }

        }
        cout<<ans<<endl;


    }
}
