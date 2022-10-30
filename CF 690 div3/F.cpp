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
        pair<int,int>p[n];
        for(int i=0; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            p[i]={b,a};
        }
        sort(p, p+n);
        int i=0, temp=0, ans=0;

        for(int j=0;j<n; )
        {
            int x=p[i].first;
            if(p[j].second<=x)
            {
                temp++;
                j++;
            }
            else{
                ans=max(ans,temp);
                i++;
                temp--;
                if (temp<0)
                    temp=0;
            }
        }
        ans=max(ans,temp);
        cout<<n-ans<<endl;
    }
}
