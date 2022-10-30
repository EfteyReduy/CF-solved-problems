///  K-Amazing number.................
#include<bits/stdc++.h>
#define inf 10000005

using namespace std;



main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n, k;
        cin>>n;
        int arr[n];

        vector<int>pos[n+1];
        //pair<int, int>p[n+1];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            pos[arr[i]].push_back(i);
        }
        int ans[n];
        for(int i=0; i<n; i++)
        {
            ans[i]=inf;
        }
        for(int i=1; i<=n; i++)
        {
            int gap=inf;
            if(pos[i].size()>0)
            {
                gap=pos[i][0];
                int j=1;
                for(j=1; j<pos[i].size(); j++)
                {
                    gap=max(gap, pos[i][j]-pos[i][j-1]-1);
                }
                gap=max(gap, n-1-pos[i][j-1]);
            }
            if(gap<inf)
            {
                ans[gap]=min(ans[gap], i);
            }
        }
        int cur=inf;
        for(int i=0; i<n; i++)
        {
            ans[i]=min(ans[i],cur);
            cur=min(cur,ans[i]);
            if(ans[i]==inf)
                ans[i]=-1;
        }
        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
}
