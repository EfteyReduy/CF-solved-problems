#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    int a=m, arr[n]={0};
    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        arr[x-1]++;

    }
    for(int i=0; i<n; i++)
    {
        a=min(a, arr[i]);
    }
    cout<<a<<endl;
}
