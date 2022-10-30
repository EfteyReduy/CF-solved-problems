#include<bits/stdc++.h>

using namespace std;

main()
{
    long long n, m, a, b, an, ans;
    cin>>n>>m>>a>>b;
    long long x=n%m;
    an=(x)*b;

    ans=(m-x)*a;

    ans=(min(an,ans));
    cout<<ans<<endl;
}
