#include<bits/stdc++.h>

#define cinarr(a,n) for(int i=0; i<n; i++)cin>>arr[i]

#define printarr(a,n) for(int i=0; i<n; i++)cout<<arr[i]<<" "; cout<<endl
#define ll long long

#define db(x) cout<<#x<<" = "<<x<<endl

using namespace std;




main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n;

        int arr[n];
        cinarr(arr,n);

        sort(arr,arr+n);

        int vis[401];
        for(int i=0; i<401; i++)
            vis[i]=0;
        map<int, int>mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }

//        for(auto i:mp)
//        {
//            vis[i.first]=1;
//            mp[i.first]--;
//        }
        int ans=0, ans2=0;

        for(int i=0; i<n; i++)
        {
            if(vis[arr[i]]==0)
            {
                vis[arr[i]]=1;
                continue;
            }
            else
            {
                for(int j=0; j<=n; j++)
                {
                    if(vis[arr[i]-j]==0 and arr[i]-1>0)
                    {
                        vis[arr[i]-j]=1;
                        ans2+=(j);
                        break;
                    }
                    else if(vis[arr[i]+j]==0)
                    {
                        vis[arr[i]+j]=1;
                        ans2+=j;
                        break;
                    }
                }
            }

        }



        for(auto i: mp)
        {
            //db(i.second);
            if(i.second>0)
            {
                int a=i.second;
                int r=a%2, b=a/2;

                int bgin=i.first-r-b;
                if(bgin<=0)
                    bgin=1;

                //db(bgin);
                for(int j=bgin; j<=2*n and a>0; j++)
                {
                    if(vis[j]==0)
                    {
                        ans+=abs(i.first-j);
                        vis[j]=1;
                        a--;
                    }

                }

            }

        }

        cout<<ans<<endl;
        cout<<ans2<<endl;

    }
}
