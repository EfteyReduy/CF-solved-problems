#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll temp=0;
void nothing(ll a, ll b)
{
    if(a==0)
    {
        return;
    }
    if(a==1)
    {
        temp+=b;
        return;
    }
    temp+=b/a;
    nothing(b%a, a);
}

main()
{
    long long a, b;
    cin>>a>>b;
    ll ans=a/b;
    a=a%b;
    nothing(a,b);
    ans+=temp;
    cout<<ans<<endl;
   // cout<<modInverse(b,a)<<endl;
}
