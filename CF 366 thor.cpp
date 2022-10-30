#include<bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int q;
    cin>>q;
    map<int, set<int> >mp;
    vector<pair<int, int> >p;
    int t=0,ans=0, strt=0;
    for(int ku=0; ku<q; ku++)
    {
        int app, type;
        cin>>type>>app;

        if(type==1)
        {
            p.push_back({app, 1});
            mp[app].insert(t);
            t++;
            ans++;
        }
        else if(type==2)
        {
            for(auto it:mp[app])
            {
                p[it].second=0;
                ans--;
                //cout<<it<<endl;
            }
            mp[app].clear();
        }
        else{

            for(int i=strt; i<app; i++)
            {
                if(p[i].second==1)
                {
                    ans--;
                    p[i].second=0;
                    mp[p[i].first].erase(i);
                }

                strt++;
            }

        }
        cout<<ans<<endl;
    }
}
