#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    map<int, int> c, r;

    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        c[n-a+b]++;
        r[a+b-1]++;
    }
    long long ans=0;
    for(auto m:c)
    {
        long long x=m.second;
        ans+=(x*(x-1))/2;
    }

    for(auto m:r)
    {
        long long x=m.second;
        ans+=(x*(x-1))/2;
    }

    cout<<ans<<endl;
}
