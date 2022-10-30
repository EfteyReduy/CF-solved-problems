#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    long long dp[n];
    dp[0]=0;
    dp[1]=abs(arr[0]-arr[1]);
    for(int i=2; i<n; i++)
    {
        dp[i]=1e18;
        for(int j=1; j<=k; j++)
        {
            if(i-j>=0)
            {
                dp[i]=min({dp[i-j]+abs(arr[i]-arr[i-j]), dp[i]});
            }

        }

    }
    cout<<dp[n-1]<<endl;

}

