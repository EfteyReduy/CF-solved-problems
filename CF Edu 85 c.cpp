#include<bits/stdc++.h>

using namespace std;





main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair<long long, long long>p[n];
        for(int i=0; i<n; i++)
        {
            cin>>p[i].first>>p[i].second;
        }
        long long adv[n];
        adv[0]=min(p[0].first, p[n-1].second);
        long long temp=adv[0], idx=0, ans=p[0].first-adv[0];
        for(int i=1; i<n; i++)
        {
            adv[i]=min(p[i].first, p[i-1].second);
            ans+=p[i].first-adv[i];
            if(adv[i]<temp)
                temp=adv[i],idx=i;
        }
        ans+=temp;
        cout<<ans<<endl;
    }
}
