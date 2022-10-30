#include<bits/stdc++.h>

using namespace std;


main()
{
    long long mod=1000000007, n;
    cin>>n;
    long long ans=1, a=2;

    while(n>0)
    {
        if(n%2)
        {
            ans=ans*a;
            n--;
            ans%=mod;

        }
        else
        {
            a=a*a;
            n/=2;
            a%=mod;
        }
    }
    cout<<ans<<endl;

}
