#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, inf=1e18;
    cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    string s[n][2];
    for(int i=0; i<n; i++)
    {
        cin>>s[i][1];
        s[i][0]=s[i][1];
        reverse(s[i][1].begin(), s[i][1].end());

    }

    long long d[n+1][2];

    for(int i=0; i<=n; i++)
    {
        d[i][0]=d[i][1]=inf;
    }

    d[0][0]=0;
    d[0][1]=arr[0];
    for(int i=1; i<n; i++)
    {
        if(d[i-1][0]!=inf)
        {
            if(s[i][0]>=s[i-1][0])
            {
                d[i][0]=min(d[i][0], d[i-1][0]);
            }
            if(s[i][1]>=s[i-1][0])
            {
                d[i][1]=min(d[i][1], d[i-1][0]+arr[i]);
            }
        }
        if(d[i-1][1]!=inf)
        {
            if(s[i][0]>=s[i-1][1])
            {
                d[i][0]=min(d[i][0], d[i-1][1]);
            }
            if(s[i][1]>=s[i-1][1])
            {
                d[i][1]=min(d[i][1], d[i-1][1]+arr[i]);
            }
        }

    }
    long long ans=min(d[n-1][0], d[n-1][1]);
//    for(int i=0; i<n; i++)
//    {
//        cout<<d[i][0]<<" "<<d[i][1]<<endl;
//    }
    if(ans>=inf)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }

}
