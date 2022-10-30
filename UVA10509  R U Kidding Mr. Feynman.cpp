#include<bits/stdc++.h>

using namespace std;

main()
{
    while(1)
    {
        double t;
        cin>>t;
        if(t==0)
        {
            break;
        }
        double d=cbrt(t);

        long long x=d;
        d=x*x*x;
        double a=x, rem=t-d;
        rem/=(3*a*a);
        a+=rem;
        cout<<fixed<<setprecision(4);
        cout<<a<<endl;


    }
}
