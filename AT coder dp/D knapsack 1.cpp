#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long w, n, k;
    cin>>n>>w;
    long long arr[n], we[n];

    long long dp[n+1][w+1];
    for(int i=0; i<n; i++)
    {
        dp[i][0]=0;
        cin>>we[i]>>arr[i];
    }
    dp[n][0]=0;
    for(int i=0; i<=w; i++)
    {
        dp[0][i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(j-we[i-1]>=0)
            {
                dp[i][j]=max(dp[i-1][j], arr[i-1]+dp[i-1][j-we[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<(dp[n][w])<<endl;

}



