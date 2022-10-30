#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, a, b, h;
        string s;
        cin>>n>>a>>b>>h;
        cin>>s;
        int one=0, z=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='1')
                one++;
            else
                z++;
        }

        long long ans=(one*b+ z*a);

        long long c0=one*h, c1=z*h;

        ans=min(ans, min(c0+n*a , c1+n*b));

        cout<<ans<<endl;

    }
}
