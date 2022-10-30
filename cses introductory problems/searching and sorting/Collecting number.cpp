#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
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
    cout<<cou<<endl;
}
