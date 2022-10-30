#include<bits/stdc++.h>
using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long l, r, m;
        cin>>l>>r>>m;
        bool pos=0;
        if(m/l)
            pos=1;

        long long  a=0, b, c;
        long long men=1e10;
        for(int i=l; i<=r; i++)
        {
            int x=m%i;
            x=min(x, i-x);
            if(x<men)
            {
                men=x;
                a=i;
            }
        }
        if(men==0)
        {
            b=l, c=l;
        }
        else{
            m=m%a;
            b=l;
            c=a-m+l;

            if(c>r){
                c=l;
                b=c+m;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<endl;

    }
}

