#include<bits/stdc++.h>

#define db(x) cout<<#x<<" = "<<x<<endl

using namespace std;


main()
{
    int st[6], n;
    for(int i=0; i<6; i++)
    {
        cin>>st[i];
    }
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(st, st+6);
    sort(arr, arr+n);
    int dp[n][6];

    for(int i=0; i<6; i++)
    {
        dp[0][i]=arr[0]-st[i];
    }

    for(int i=1; i<n-1; i++)
    {
        for(int j=0; j<6; j++)
        {
            int dif=1000000001, a=arr[i]-st[j];
            dp[i][j]=a;
            //int x=abs(a-dp[i-1][0]), y=abs(a-dp[i][1]), z=abs(a-dp[i][2]), p=abs(a-dp[i][3]), q=abs(a-dp[i][4]), r=abs(a-dp[i][5]);
            for(int k=0; k<6; k++)
            {
                int b=abs(a-dp[i-1][k]);
                if(b<=dif)
                {
                    dif=b;
                    dp[i][j]=min(dp[i][j], dp[i-1][k]);
                }
            }
        }
    }
    int ans=0;
    int dif=1000000001;
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            dif=min(dif, abs(dp[n-2][i]-(arr[n-1]-st[j])));
            //db(dp[n-2][j]);
            //db(st[i]);
            ans=max(ans,abs(arr[n-1]-dp[n-2][j]-st[i]));
        }
    }
    cout<<dif<<endl;

    //cout<<ans<<endl;


}
