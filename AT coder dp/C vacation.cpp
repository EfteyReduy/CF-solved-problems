#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n;
    long long arr[n];

    long long dp[3][n+1];
    dp[0][0]=0;
    dp[1][0]=0;
    dp[2][0]=0;
    for(int i=1; i<=n; i++)
    {
        long long a, b, c;
        cin>>a>>b>>c;

        dp[0][i]=a+max(dp[1][i-1], dp[2][i-1]);
        dp[1][i]=b+max(dp[0][i-1], dp[2][i-1]);
        dp[2][i]=c+max(dp[1][i-1], dp[0][i-1]);

    }
    cout<<max({dp[0][n], dp[1][n], dp[2][n]})<<endl;

}


