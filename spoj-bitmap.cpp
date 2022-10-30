#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        string s[n];
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
        }
        queue<pair< pair<int, int>, int> >q;
        int st[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                st[i][j]=1000;
                if(s[i][j]=='1')
                {
                    st[i][j]=0;
                    pair<pair<int, int>, int> p={{i, j}, 0};
                    q.push(p);
                }
            }
        }

        while(!q.empty() )
        {
            pair< pair<int, int>, int> p=q.front();
            q.pop();
            int x=p.first.first, y=p.first.second, d=p.second+1;
            if(x+1<n)
            {
                if(st[x+1][y]>d)
                {
                    st[x+1][y]=d;
                    q.push({{x+1, y}, d});
                }
            }

            if(x-1>=0)
            {
                if(st[x-1][y]>d)
                {
                    st[x-1][y]=d;
                    q.push({{x-1, y}, d});
                }
            }

            if(y+1<m)
            {
                if(st[x][y+1]>d)
                {
                    st[x][y+1]=d;
                    q.push({{x, y+1}, d});
                }
            }

            if(y-1>=0)
            {
                if(st[x][y-1]>d)
                {
                    st[x][y-1]=d;
                    q.push({{x, y-1}, d});
                }
            }

        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<st[i][j]<<" ";
            }
            cout<<endl;
        }


    }
}
