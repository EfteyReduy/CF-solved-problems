#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, m, a, b;
        cin>>n>>m>>a>>b;
        if(n<m)
        {
            swap(n,m);
        }

        long long x=(n-m);

        a=a-x;
        x=m-b;

        if(a<0)
            a=0;
        if(x>=0)
        {
            long long y=a+b;
            if(y<=2*m)
            {
                cout<<"YES"<<endl;
                continue;
            }

        }
        cout<<"NO"<<endl;

    }
}
