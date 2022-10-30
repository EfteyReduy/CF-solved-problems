#include<bits/stdc++.h>

using namespace std;

main()
{
    long long k, a, b;
    cin>>k>>a>>b;

    long long x=a/k, y=b/k, ans=0;

    if(x and y)
        ans=x+y;
    else if(x==0)
    {
        if(b%k==0)
        {
            ans=x+y;
        }
        else
        {
            ans=-1;
        }
    }
    else if(y==0)
    {
        if(a%k==0)
        {
            ans=x+y;
        }
        else
        {
            ans=-1;
        }
    }

    if(ans)
    {
        cout<<ans<<endl;
    }
    else
        cout<<-1<<endl;

}
