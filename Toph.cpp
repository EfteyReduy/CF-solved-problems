#include<bits/stdc++.h>


using namespace std;
bool comp(const vector<int> &a,  const vector<int> &b)
{
       return (a.size() < b.size());
}


main()
{

    int n, m;
    cin>>n>>m;
    vector<int>g[n];

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    sort(g, g+n, comp);
    int ans=0;
    bool x=false;
    for(int i=0; i<n; i++)
    {
        if(g[i].size()==1)
        {
            cout<<"here"<<endl;
            ans++;
        }
        else if(g[i].size()==0)
        {
            x=true;
            ans++;
        }
    }
    if(!x)
        ans--;

    cout<<ans<<endl;

    return 0;
}
