#include<bits/stdc++.h>

using namespace std;


char siftup(char ch)
{
    if(ch=='z')
        return 'a';
    return ch+1;
}
char siftdn(char ch)
{
    if(ch=='a')
        return 'z';
    return ch-1;
}


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        string strt, ind;
        cin>>strt>>ind;
        string a, b, c;
        int n;
        cin>>n;
        unordered_map<string, bool>forbiden, vis, alin;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b>>c;
            for(int i=0; i<a.length(); i++)
            {
                for(int j=0; j<b.length(); j++)
                {
                    for(int k=0; k<c.length(); k++)
                    {
                        string x="abc";
                        x[0]=a[i];
                        x[1]=b[j];
                        x[2]=c[k];
                        forbiden[x]=1;
                       // cout<<x<<endl;
                    }
                }
            }
        }



        queue<pair<string, int> >q;
        q.push({strt,0});
        if(forbiden[strt])
            q.pop();
        int ans=-1;
        int cou=0;
        while(!q.empty())
        {
            pair<string , int>p=q.front();
            cou++;
            //cout<<p.first<<" "<<p.second<<" "<<cou<<endl;
            q.pop();
            vis[p.first]=1;
            alin[p.first]=1;
            if(p.first==ind)
            {
                ans=p.second;
                break;
            }
            int x=p.second;
            for(int i=0; i<3; i++)
            {
                string ss=p.first;
                ss[i]=siftup(ss[i]);
                if(!forbiden[ss] and !vis[ss] and !alin[ss])
                {
                    q.push({ss, x+1});
                    alin[ss]=1;
                }
                ss[i]=siftdn(ss[i]);
                ss[i]=siftdn(ss[i]);
                if(!forbiden[ss] and !vis[ss] and !alin[ss])
                {
                    q.push({ss,x+1});
                    alin[ss]=1;
                }
            }

        }
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}
