#include<bits/stdc++.h>

using namespace std;

long long ncr(int n, int r)
{
    long long ans=1;
    if(n==r)
        return ans;

    r=max(r, (n-r));
    for(int i=r+1; i<=n; i++)
    {
        ans=ans*i;
        ans=(ans/(i-r));
    }
    return ans;

}

main()
{
    long long n, m, t, ans=0;
    cin>>n>>m>>t;

    for(int i=4; i<=n and i<t; i++)
    {
        if(t-i>m)
            continue;
        long long boys=ncr(n, i), girls=ncr(m, t-i);
        ans+=(boys*girls);
    }
    cout<<ans<<endl;

}
