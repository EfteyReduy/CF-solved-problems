#include<bits/stdc++.h>


using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int L, v, l, r;
        cin>>L>>v>>l>>r;
        int to=L/v, s=(r/v)-(l/v);
        int ans=to-s-1;
        if(l%v!=0)
            ans++;
        cout<<ans<<endl;

    }
}
