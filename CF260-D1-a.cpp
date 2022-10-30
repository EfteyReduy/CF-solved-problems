#include<bits/stdc++.h>


using namespace std;
long long arr[100002];
main()
{
    long long n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        long long a;
        cin>>a;
        arr[a]+=a;
    }
    long long dp[100002][2];
    dp[0][0]=0,dp[0][1]=0;
    for(int i=1; i<100002; i++)
    {

        dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
        dp[i][1]=dp[i-1][0]+arr[i];
        //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    cout<<max(dp[100001][1],dp[100001][0])<<endl;
}
