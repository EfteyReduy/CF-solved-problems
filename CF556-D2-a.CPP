#include<bits/stdc++.h>
using namespace std;

main()
{
    int n, m, t;
    cin>>n>>m>>t;
    int mi=1000000000, ma=0;

    for(int i=0; i<n; i++)
    {
        int a;cin>>a;
        if(a<mi)
        {
            mi=a;
        }
    }

    for(int i=0; i<m; i++)
    {
        int a;cin>>a;
        if(a>ma)
        {
            ma=a;
        }
    }
    if(ma<mi)
    {
        cout<<t<<endl;
    }else{
        int a=t/mi;
        int r=t%mi;
        a=a*(ma);
        a+=r;
        cout<<a<<endl;
    }
}
