#include<bits/stdc++.h>

using namespace std;

main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>g[n];
        for(int i=0; i<n; i++ )
        {
            int a;
            cin>>a;
            a--;
            g[i].push_back(a);
        }
//        for(int i=0; i<n; i++)
//        {
//            cout<<g[i][0]<<" ";
//        }
//        cout<<endl;
//        continue;
        bool vis[n];
        for(int i=0; i<n; i++)
        {
            vis[i]=false;
        }
        int finl[n];
        vector<int>pos;
        for(int i=0; i<n; i++)
        {

            if(!vis[i])
            {
                vis[i]=true;
                int strt=i;
                int x=g[i][0];
                int ans=1;
                pos.push_back(x);
                //pos.push_back(i);
                while(x!=i)
                {
                    //cout<<"here x = "<<x<<endl;
                    //vis[x]=true;
                    x=g[x][0];
                    pos.push_back(x);
                    ans++;
                    vis[x]=1;
                }
                //cout<<" ans = "<<ans<<endl;
                for(int j=0; j<pos.size(); j++)
                {
                    //cout<<"position " <<j<<" value "<<pos[j]<<" ans ="<<ans<<endl;
                    finl[pos[j]]=ans;
                    vis[pos[j]]=true;
                }
                pos.clear();
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<finl[i]<<" ";
        }
        cout<<endl;

    }

}
