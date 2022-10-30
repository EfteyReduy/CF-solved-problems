#include<bits/stdc++.h>

using namespace std;

main()
{
    long long n, ans=1;;
    cin>>n;
    for(long long i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            ans=ans*i;
            while(n%i==0)
                n=n/i;
        }
    }
    //cout<<n<<endl;
    ans=ans*n;
    cout<<ans<<endl;
}
