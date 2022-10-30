#include<bits/stdc++.h>

using namespace std;

main()
{

    long long ans=1, n;
    cin>>n;
    long long a=n;
    n--;

    while(n>0)
    {
        ans=ans*n;
        n--;
    }
    ans=(ans*2)/a;
    cout<<ans<<endl;

}
