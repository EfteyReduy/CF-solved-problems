#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    map<int, long long>x, y;
    map<pair<int, long long>, int>xy;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        x[a]++;
        y[b]++;
        xy[{a,b}]++;
    }
    long long ans=0;
    for(auto i:x)
    {
        long long a=i.second;
        ans+=((a*(a-1))/2);
    }
    for(auto i:y)
    {
        long long a=i.second;
        ans+=((a*(a-1))/2);
    }

    for(auto i:xy)
    {
        long long a=i.second;
        ans-=((a*(a-1))/2);
    }
    cout<<ans<<endl;

}
