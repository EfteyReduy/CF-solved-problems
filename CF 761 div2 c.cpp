#include<bits/stdc++.h>

using namespace std;
struct cmpStruct {
    bool operator() (const int &a, const int &b)
    {
        return a>b;
    }
};
main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        map<int, int>mp;
        bool vis[n+1];
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            mp[arr[i]]++;
            if(arr[i]<=n and !vis[arr[i]]){
                vis[arr[i]]=1;
                mp[arr[i]]--;
            }
        }
        set<int, cmpStruct> rem;

        for(int i=0; i<n; i++)
        {
            if(mp[arr[i]]>0 or arr[i]>n)
            {
                rem.insert(arr[i]);

            }
        }
        int ans=0;
        bool pos=true;
        for(int i=n; i>0; i--)
        {
            if(!vis[i])
            {
                int x=*rem.begin();
               // cout<<"X = "<<x<<" at i = "<<i<<endl;
                if(x<=2*i)
                {
                    pos=false;
                }
                mp[x]--;
                if(mp[x]<=0)
                {
                    rem.erase(x);
                }
                ans++;
            }
        }
        if(pos)
        {
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }

    }
}
