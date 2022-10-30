#include<bits/stdc++.h>

using namespace std;



main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin>>n;
    long long ans=0;
    bool pos=true;
    for(long long i=2; i*i<=n; i++)
    {
        if(n%i==0 and ans!=0)
        {
            ans=ans*i;
            pos=true;
            break;
        }
        if(n %i==0)
        {
            ans=i;
            n=n/i;
            pos=false;
            if(n%i==0 and i<n)
            {
                ans*=i;
                pos=true;
                break;
            }
        }
    }
    if(pos)
    {
        cout<<1<<endl;
        cout<<ans<<endl;
    }
    else{
        cout<<2<<endl;
    }
}
