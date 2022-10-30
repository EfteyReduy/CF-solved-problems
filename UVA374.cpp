#include<bits/stdc++.h>
using namespace std;

main()
{
    long long a, b, m, ans;
    cin>>a>>b>>m;
    ans=1;

    for(int i=0; i<b; i++)
    {
        ans=((ans)*(a))%m;
    }
    cout<<ans<<endl;
    /// solution not completed yet....
}
