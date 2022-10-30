#include<bits/stdc++.h>

using namespace std;



void ces(int cas)
{
    cout<<"Case "<<cas<<": ";
}

vector<int>g[30000+2];
bool vis[30002];
int w[30002];
int sign[30002];
int total=0;
int pos_c=0;
void dfs(int v, bool sgn){
    if(vis[v])
    {
        return;
    }
    vis[v]=1;
    if(sgn){
        total+=w[v];
        pos_c++;
        sign[v]=1;
    }
    else{
        total-=w[v];
        sign[v]=-1;
    }
    for(auto it:g[v]){
        dfs(it, !sgn);
    }
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;

    for(int tt=1; tt<=t; tt++)
    {
        memset(vis, 0, sizeof(vis));
        memset(g, 0, sizeof(g));
        memset(w, 0, sizeof(w));
        memset(sign, 0, sizeof(sign));
        total =0;
        pos_c = 0;
        int n;
        cin>>n;

        for(int i=1; i<=n; i++)
        {
            cin>>w[i];
        }

        for(int i=0; i<n-1; i++)
        {
            int a, b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, 1);
        int ans=1;
        int sum = 0;

        int x = -(n - 2*pos_c);
        //cout<<"x = "<<x<<endl;

        for(int i=1; i<=n; i++)
        {
            int temp=0;
            if(sign[i]>0)
            {
                temp = x*w[i];
                temp-=total;
            }
            else{
                temp = -x*w[i];
                temp+=total;
            }


            if(sum<temp)
            {
                sum = temp;
                ans = i;
            }
            //cout<<"Temp = "<<temp<<endl;
        }
        ces(tt);
        cout<<ans<<endl;

        //cout<<total<<endl;
    }

    return 0;
}
