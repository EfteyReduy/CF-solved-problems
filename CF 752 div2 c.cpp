#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a, b;
        cin>>a>>b;
        if(a>b)
        {
            cout<<a+b<<endl;
        }
        else if(a==b)
        {
            cout<<a<<endl;
        }
        else{
            long long x=(a*(b/a)+b);
            x/=2;
            cout<<x<<endl;
        }
    }
    return 0;
}
