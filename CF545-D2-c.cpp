#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    pair<int, int> p[n];
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;
        p[i]=make_pair(a,b);
    }
    int ans=1;
    for(int i=1; i<n-1; i++)
    {
        if(p[i].first-p[i-1].first>p[i].second)
            ans++;
        else if(p[i+1].first-p[i].first>p[i].second)
        {
            p[i].first=p[i].first+p[i].second;
            ans++;
        }
    }
    if(n>1)
        ans++;
    cout<<ans<<endl;
}
