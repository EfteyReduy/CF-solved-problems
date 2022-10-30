#include<bits/stdc++.h>


using namespace std;

main()
{
    int n, k;
    cin>>n>>k;
    int arr[n], brr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>brr[i];
    }
    pair<int, int> p[n];

    for(int i=0;i<n; i++)
    {
        p[i]=make_pair(arr[i]-brr[i], i);
    }
    sort(p, p+n);
    bool mark[n]={0};
    for(int i=0;i<k; i++)
    {
        mark[p[i].second]=1;
    }
    int i=k;
    int a=p[i].first;
    while(a<0)
    {
        mark[p[i].second]=1;
        i++;
        a=p[i].first;
    }
    while(i<n)
    {
        mark[p[i].second]=0;
        i++;
    }
    long long ans=0;
    for( i=0; i<n; i++)
    {
        if(mark[i])
            ans+=arr[i];
        else
            ans+=brr[i];
    }
    cout<<ans<<endl;




}
