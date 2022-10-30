#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    pair<int, int> arr[n];
    int i, j;
    for(i=0; i<n; i++)
    {
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr, arr+n);
    int m, a;
    cin>>m;
    long long v=0, p=0;
    for(i=0; i<m; i++)
    {
        cin>>a;
        v=v+arr[a-1].second+1;
        p=p+n-arr[a-1].second;
    }
    cout<<v<<" "<<p<<endl;
}
