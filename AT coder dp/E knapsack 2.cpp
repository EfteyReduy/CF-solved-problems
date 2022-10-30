#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long w, n, k=0;
    cin>>n>>w;
    long long arr[n], we[n];

    for(int i=0; i<n; i++)
    {
        cin>>we[i]>>arr[i];
        k+=arr[i];
    }
    long long dp[n+1][k+1];
    for(int i=0; i<n; i++)
    {
        dp[i][0]=0;
    }
    dp[n][0]=0;
    for(int i=1; i<=k; i++)
    {
        dp[0][i]=1e15;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(j-arr[i-1]>=0)
            {
                dp[i][j]=min(dp[i-1][j], we[i-1]+dp[i-1][j-arr[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    long long ans=0;
    for(long long i=0; i<=k; i++)
    {
        if(dp[n][i]<=w)
        {
            ans=max(ans, i);
        }
    }
    cout<<(ans)<<endl;

}




