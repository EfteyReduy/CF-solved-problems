#include<bits/stdc++.h>

using namespace std;


main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, vector<string>>g;
    int coc=0;
    while(1)
    {
        string a, b;
        cin>>a>>b;
        coc++;
        if(a=="*" and b=="*")
        {
            break;
        }
        unordered_map<string, bool>vis;
        queue<pair<string, int>>q;
        q.push({a, 0});
        int ans=0;
        vis[a]=1;
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }

        vector<string>as, bs;
        as.push_back(a);
        bs.push_back(b);
        unordered_map<string, bool>ap, bp;
        ap[a]=1;
        bp[b]=1;
        int temp=1;
        while(1)
        {
            vector<string>bst, ast;
            for(int k=0; k<as.size(); k++)
            {
                string str=as[k];
                vis[str]=1;
                for(int i=2; i<=10; i++)
                {
                    for(int j=0; i+j<=10; j++)
                    {
                        string st=str;
                        reverse(st.begin()+j, st.begin()+i+j);
                        if(bp[st])
                        {
                            ans=temp;
                            break;
                        }
                        else{
                            if(!vis[st])
                            {
                                vis[st]=1;
                                ast.push_back(st);
                                ap[st]=1;
                            }
                        }
                    }
                    if(ans)
                    {
                        break;
                    }
                }
                if(ans)
                {
                    break;
                }
            }
            as=ast;
            //ast.clear();
            if(ans)
            {
                break;
            }
            temp++;
            for(int k=0; k<bs.size(); k++)
            {
                string str=bs[k];
                vis[str]=1;
                for(int i=2; i<=10; i++)
                {
                    for(int j=0; i+j<=10; j++)
                    {
                        string st=str;
                        reverse(st.begin()+j, st.begin()+i+j);
                        if(ap[st])
                        {
                            ans=temp;
                            break;
                        }
                        else{
                            if(!vis[st])
                            {
                                vis[st]=1;
                                bst.push_back(st);
                                bp[st]=1;
                            }
                        }
                    }
                    if(ans)
                    {
                        break;
                    }
                }
                if(ans)
                {
                    break;
                }
            }
            bs=bst;
            //bst.clear();
            temp++;
            if(ans)
            {
                break;
            }
        }
        if(coc==2)
            cout<<coc;
        cout<<ans<<endl;
    }
}
