#include<bits/stdc++.h>

using namespace std;
bool vis[1000][1000][8];
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n>>m;

        string s[n];
        int  dis[n][m];


        for(int i=0; i<n ; i++)
        {
            cin>>s[i];

        }
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dis[i][j]=10000000;
            }
        }
        int si, sj, fi, fj;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='S')
                {
                    si=i;
                    sj=j;
                }
                if(s[i][j]=='F')
                {
                    fi=i;
                    fj=j;
                }
            }
        }

        bool viss[n][m];
        memset(viss, 0, sizeof(viss));

        queue<pair<pair<int, int>, int> >q;
        dis[si][sj]=0;
        q.push({{si, sj}, 0});
        int x[]={0, 1, 1, -1, 0, -1, -1, 1 };
        int y[]={-1, 0, 1, 1, 1, 0, -1, -1 };
        int ans=0;
        viss[si][sj]=1;
        while(!q.empty())
        {
            //cout<<"here";
            auto it=q.front();
            q.pop();
            int a, b, d;
            a=it.first.first;
            b=it.first.second;
            d=it.second;
            //cout<<" at "<<a<<" "<<b<<endl;
            for(int k=0; k<4; k++)
            {
                int kk=(k+4);
                for(int i=a+x[k], j=b+y[k]; i<n and i>=0 and j>=0 and j<m; j+=y[k], i+=x[k])
                {

                    if(i==fi and j==fj)
                    {
                        ans=d+1;
                        break;
                    }
                    if(vis[i][j][k]==1 or s[i][j]=='X')
                    {
                        break;
                    }
                    else //if(vis[i][j][kk]==0)
                    {
                        vis[i][j][k]=1;
                        dis[i][j]=min(d+1, dis[i][j]);
                        if(!viss[i][j])
                            q.push({{i, j}, dis[i][j]}), viss[i][j]=1;
                    }
                }
                if(ans)
                    break;

                for(int i=a+x[kk], j=b+y[kk]; i<n and i>=0 and j>=0 and j<m; j+=y[kk], i+=x[kk])
                {

                    if(i==fi and j==fj)
                    {
                        ans=d+1;
                        break;
                    }
                    if(vis[i][j][k]==1 or s[i][j]=='X')
                    {
                        break;
                    }
                    else //if(vis[i][j][kk]==0)
                    {
                        vis[i][j][k]=1;
                        dis[i][j]=min(d+1, dis[i][j]);
                        if(!viss[i][j])
                            q.push({{i, j}, dis[i][j]}), viss[i][j]=1;
                    }
                }
                if(ans)
                    break;
            }
            if(ans)
                break;
        }

//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<m; j++)
//            {
//                cout<<dis[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        if(ans==0)
        {
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }

    }
}

