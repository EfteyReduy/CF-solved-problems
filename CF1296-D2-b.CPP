#include<bits/stdc++.h>

using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, ans;
        cin>>n;
        ans=n;
        while(n/10)
        {
            ans=ans+(n/10);
            n=(n/10)+(n%10);
        }
        cout<<ans<<endl;

    }
}
