#include<bits/stdc++.h>

using namespace std;


main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int cap[5001];

    for(int i=0; i<5001; i++)
    {
        cap[i]=0;
    }

    for(int i=0; i<n; i++)
    {
        cap[ arr[i] ]++;
    }
    int ans=0, brr[n];
    brr[0]=cap[0];
    for(int i=1; i<=5000; i++)
    {
        brr[i]=brr[i-1]+cap[i];
    }

    for(int i=1; i*2<=5000; i++)
    {
        int temp=brr[i*2]-brr[i-1];
        ans=max(temp, ans);
    }

    ans=n-ans;

    cout<<ans<<endl;
}
