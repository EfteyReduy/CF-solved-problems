#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long c1, c2, ans=0, x=0;
        long long t1, t2;
        long long w1, w2;
        cin>>c1>>c2>>t1>>t2>>w1>>w2;

        long long capacity=c1+c2;

        long long ts=t1*w1, tw=t2*w2;
        long long tcs=capacity/w1, tcw=capacity/w2;
        long long a=min(tcs, t1);
        long long b=min(tcw, t2);

        if(w1<=w2)
        {
            capacity-=(a*w1);
            ans=a;
            x=(capacity/w2);
            x=min(x, b);
            ans+=x;
        }
        else{
            capacity-=(b*w2);
            ans=b;
            x=(capacity/w1);
            x=min(x, a);
            ans+=x;
        }
        cout<<ans<<endl;

    }
}
