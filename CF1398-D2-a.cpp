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
        int  j, k, l, m1=1e5, m2=1e5, mex=0;
        pair<int, int>arr[n];
        for(int i=0;i<n; i++)
        {
            cin>>arr[i].first;
            arr[i].second=i+1;

        }
        sort(arr, arr+n);



        int ans=arr[n-1].first-arr[1].first-arr[0].first;
        j=arr[0].second;
        k=arr[1].second;
        l=arr[n-1].second;


        if(ans<0)
        {
            cout<<-1<<endl;
        }
        else{
            cout<<j<<" "<<k<<" "<<l<<endl;
        }
    }
}
