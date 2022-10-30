#include<bits/stdc++.h>

using namespace std;

main()
{
    long long a, b;
    cin>>a>>b;

    long long c=__gcd(a,b);
    int ans=0;
    a=a/c;
    b=b/c;
    while(a%2==0)
    {
        a=a/2;
        ans++;
    }

    while(a%3==0)
    {
        a=a/3;
        ans++;
    }

    while(a%5==0)
    {
        a=a/5;
        ans++;
    }

    while(b%2==0)
    {
        b=b/2;
        ans++;
    }

    while(b%3==0)
    {
        b=b/3;
        ans++;
    }

    while(b%5==0)
    {
        b=b/5;
        ans++;
    }

    if(a==b and a==1)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;


}
