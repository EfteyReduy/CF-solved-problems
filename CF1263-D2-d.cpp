#include<bits/stdc++.h>

using namespace std;


int vis[26];
set<char> g[26];
void dfs(char ch)
{
    int v=ch-'a';
    vis[v]=1;
    for(auto i:g[v])
    {
        if(vis[i-'a']==0)
            dfs(i);
    }
    return;
}


main()
{
    int n;
    cin>>n;
    string s[n];

    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        //sort(s[i].begin(), s[i].end);
    }
    for(int i=0; i<26; i++)
    {
        vis[i]=-1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<s[i].size(); j++)
        {
            int v=s[i][j]-'a';
            for(int k=0; k<s[i].size(); k++)
            {
                g[v].insert(s[i][k]);

            }
            vis[v]=0;
        }
    }
    int ans=0;
    for(int i=0; i<26; i++)
    {

        if(vis[i]==0)
            dfs(*g[i].begin()),ans++;;

    }
    cout<<ans<<endl;


}
