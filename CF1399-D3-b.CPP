#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long a[n], b[n], i, j, x, y, ans=0, ma=1000000001, mb=10000000001;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            ma=min(a[i],ma);
        }

        for(i=0; i<n; i++)
        {
            cin>>b[i];
            mb=min(b[i],mb);
        }

        for(i=0; i<n; i++)
        {
            x=a[i]-ma;
            y=b[i]-mb;
            ans=ans+max(x,y);
        }
        cout<<ans<<endl;
    }
}
