#include<bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int n;
        cin>>n;
        vector<int>v;
        for(int i=1; i<=n; i++)
        {
            v.push_back(i);
        }
        pair<int, char> p[n+1][n+1];

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int x=0;
                char st;
                string sst;
                cin>>sst;
                for(int ii=1; ii<sst.length()-1; ii++)
                {
                    x=x*10;
                    x+=(sst[ii]-'0');
                }
                cin>>sst;
                st = sst[0];
                p[i][j]={x, st};
                //cout<<x<<", "<<st<<" ";
            }
            //cout<<endl;
        }
        long long ans=0, temp=0;
        do{
            int p1 = v[0], p2 = v[1];
            ans += p[p1][p2].first;
            for(int i=2; i<n; i++)
            {
                if(p[p1][p2].second=='T'){
                    p2=v[i];
                }
                else{
                    p1=p2;
                    p2=v[i];
                }
                ans+= p[p1][p2].first;
            }
            temp = max(temp, ans);
            ans=0;
        }while(next_permutation(v.begin(), v.end()));

        cout<<"Case "<<tt<<": ";
        cout<<temp<<endl;

    }
}
