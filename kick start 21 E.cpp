#include<bits/stdc++.h>


using namespace std;


main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        string s;
        cin>>s;
        bool pos=true;

        map<char, int>ch;
        for(int i=0; i<s.length(); i++)
        {
            ch[s[i]]++;
        }
        vector< pair<int, char> >p;
        for(auto it:ch)
        {
            p.push_back({it.second, it.first});
            if(it.second>(s.length())/2)
            {
                pos=false;
                break;
            }
        }

        cout<<"case #"<<cas<<": ";
        if(pos)
        {
            int n=s.length();
            char ans[n];
            bool vis[n];
            memset(vis, 0, sizeof(vis));
            sort(p.begin(), p.end());
            int jj=1;
            for(int i=p.size()-1; i>=0; i--)
            {
                char cc=p[i].second;
                int x=p[i].first;
                for(int j=0; j<x; )
                {
                    char carTosub=p[(i-jj)%p.size()].second;
                    //cout<<"here at i = "<<i<<" and carTosub = "<<carTosub<<" and cc = "<<cc<<endl;
                    for(int k=0; k<n; k++)
                    {
                        if(s[k]==carTosub and !vis[k] and j<x)
                        {
                            ans[k]=cc;
                            vis[k]=1;
                            j++;

                        }
                        if(j>=x)
                        {
                            jj--;
                            break;
                        }
                    }
                    jj++;
                }

            }
            for(int xx=0; xx<n; xx++)
            {
                cout<<ans[xx];
            }
            cout<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
