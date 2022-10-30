#include<bits/stdc++.h>
using namespace std;


main()
{
    int n, m, k;
    cin>>n>>m>>k;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    pair<pair<int, int> , long long> p[m];
    for(int i=0; i<m; i++)
    {
        int a, b;
        long long x;
        cin>>a>>b>>x;
        p[i]={{a, b}, x};
    }
    long long brr[m+1];
    for(int i=0; i<=m; i++)
    {
        brr[i]=0;
    }
    for(int i=0; i<k; i++)
    {
        int a, b;
        cin>>a>>b;
        brr[a-1]++;
        brr[b]--;

    }
    for(int i=1; i<=m; i++)
    {
        brr[i]+=brr[i-1];

    }

///so far so good...............

    long long res[n+1];
    for(int i=0; i<=n; i++)
    {
        res[i]=0;
    }
    for(int i=0; i<m ;i++)
    {
        int a=p[i].first.first, b=p[i].first.second;
        long long x=p[i].second;

        res[a-1]+=(x*brr[i]);
        res[b]-=(x*brr[i]);

    }
    for(int i=1; i<n; i++)
    {
        res[i]+=res[i-1];
    }

    for(int i=0; i<n; i++)
    {
        cout<<res[i]+arr[i]<<" ";
    }
    cout<<endl;


}
