#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    pair<int, int>p[n];
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;

        p[i]={b,a};

    }

    sort(p, p+n);
    int ans=1, nxt=p[0].first;

    for(int i=1; i<n; i++)
    {
        if(p[i].second>=nxt)
        {
            ans++;
            nxt=p[i].first;
        }
    }
    cout<<ans<<endl;



}
