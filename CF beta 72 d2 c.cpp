#include<bits/stdc++.h>

using namespace std;

bool sorting(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first < b.first);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    pair<int, int>pxc[n];
    for(int i=0 ; i<n; i++)
    {
        int c, r;
        cin>>c>>r;
        pxc[i]={c,r};
    }

    int m;
    cin>>m;
    pair<int, int> p[m];
    map<pair<int, int>, int>mp;
    for(int i=0; i<m; i++)
    {
        cin>>p[i].first>>p[i].second;
        if(mp[p[i]]==0)
            mp[p[i]]=i+1;

    }
    sort(p, p+m);

    int ans[n];
    memset(ans, -1, sizeof(ans));

    for(int i=0; i<n; i++)
    {
        int a=pxc[i].first, b=pxc[i].second;
        pair<int, int>pp={a-b, 0};
        auto it=lower_bound(p, p+m, pp, sorting);
        pp=*it;
        //cout<<pp.first<<" "<<pp.second<<endl;
        int x=a+b, j=it-(p);
        //cout<<"value of j is : "<<j<<endl;
        while(x>=p[j].first and j<m)
        {
            //cout<<"here"<<endl;
            int val=(a-p[j].first);
            val=val*val;
            val=val+(p[j].second*p[j].second);
            if(val<=b*b)
            {
                if(ans[i]==-1)
                    ans[i]=mp[p[j]];
                else{
                    ans[i]=min(ans[i], mp[p[j]]);
                }
            }
            j++;
        }
    }
    int cou=0;
    for(int i=0; i<n; i++)
    {
        if(ans[i]!=-1)
            cou++;
    }
    cout<<cou<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
