#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        long long ans=0;
        cin>>x;
        int a=x/2, b=x/2;
        bool pp = x&1;
        for(int i=1; i<=x/3; i++)
        {
            if((x-i)%2==0)
            {
                ans++;
            }
            if(x%i==)
            ans+=min(a-b, );
        }

        cout<<ans<<endl;
    }
}


