#include<bits/stdc++.h>


using namespace std;
string s[501];
int n, m, k, vis[501][501], cou=0;

vector<pair<int, int> >p;

void dfs(int i, int j)
{
    if(i>=n or j>=m or i<0 or j<0)
    {
        return;
    }
    if(vis[i][j]!=0)
    {
        return;
    }
    vis[i][j]=1;
    cou++;

    p.push_back({i, j});
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i, j-1);

}
int rr;

void dfs2(int i, int j)
{
    if(i>=n or j>=m or i<0 or j<0)
    {
        return;
    }
    if(vis[i][j]==-1)
    {
        return;
    }
    vis[i][j]=-1;
    cou++;
    if(cou>rr)
    {
        s[i][j]='X';
    }
    //cout<<cou<<endl;
    dfs2(i-1, j);
    dfs2(i+1, j);
    dfs2(i, j+1);
    dfs2(i, j-1);
    //cout<<"I checked all the neighbors."<<endl;
}


int main()
{

    cin>>n>>m>>k;

    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    int obs=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            vis[i][j]=0;
            if(s[i][j]=='#')
            {
                obs++;
                vis[i][j]=-1;
            }
        }
    }
    int rem=(m*n-obs-k), idx, jdx;
    rr=rem;
    bool found=false;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m ;j++)
        {
            if(vis[i][j]==0)
            {
                dfs(i, j);
                if(cou<rem or found)
                {
                    for(auto it:p)
                    {
                        s[it.first][it.second]='X';
                        vis[it.first][it.second]=-1;
                    }
                }
                else{
                    found=true;
                    idx=p[0].first;
                    jdx=p[0].second;
                }

                p.clear();
                cou=0;
            }
        }
    }
    dfs2(idx, jdx);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }



}
