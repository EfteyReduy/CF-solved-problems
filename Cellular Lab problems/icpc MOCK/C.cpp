#include<bits/stdc++.h>

using namespace std;

main()
{
    int t, x=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long ans=0, sum=0;
        for(int i=0; i<n-1; i++)
        {
            long long a, b;
            cin>>a>>b;
            sum+=a;
            sum-=b;
            ans=max(ans, sum);
        }
        cout<<"Case "<<x<<": "<<ans<<endl;
        x++;
    }
}

