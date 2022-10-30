#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0]=1;
    sort(arr, arr+n);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=x; j++)
        {

            if(arr[i-1]<=j)
            {
                dp[i][j]=(dp[i][j-arr[i-1]]+dp[i-1][j]);

                dp[i][j]=dp[i][j]%(1000000007);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][x]<<endl;
}
