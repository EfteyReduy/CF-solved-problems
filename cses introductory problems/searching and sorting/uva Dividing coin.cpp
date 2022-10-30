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
        long long arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
        }
        int m=sum/2;
        //cout<<sum<<" "<<m<<endl;
        m;
        long long dp[n+1][(sum/2)+1];
        for(int i=0; i<=n; i++)
            dp[i][0]=0;
        for(int i=0; i<=m; i++)
            dp[0][i]=0;
//
//        for(int i=0; i<=n; i++)
//        {
//            for(int j=0; j<=m; j++)
//            {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(j>=arr[i-1])
                    dp[i][j]=max(dp[i-1][j], arr[i-1]+dp[i-1][j-arr[i-1]]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }

        long long temp, ans=1000000, half=sum/2;
        cout<<sum-(2*dp[n][m])<<endl;
    }
}
