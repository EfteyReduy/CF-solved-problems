#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m;
    cin>>n>>m;

    long long arr[n];
    pair<long long, int>p[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        p[i]={arr[i], i};
    }

    sort(p, p+n);

    int cou=1;
    for(int i=0; i<n-1; i++)
    {
        if(p[i].second>p[i+1].second)
        {
            cou++;
        }
    }

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        swap(arr[a-1], arr[b-1]);
        a=arr[a-1], b=arr[b-1];
    }

    //cout<<cou<<endl;
}
