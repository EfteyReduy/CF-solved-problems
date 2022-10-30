#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<g[i].size()+1<<endl;
        cout<<i<<" "<<i<<endl;
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<i<<" "<<g[i][j]<<endl;
        }
    }
}
