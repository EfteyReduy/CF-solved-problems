#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    string s, t;
    cin>>s>>t;
    n=s.length();
    m=t.length();

    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans="";
    int i=n,j=m;
    while(i>0 or j>0)
    {
        if(dp[i][j]>dp[i-1][j] and dp[i][j]>dp[i][j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]==dp[i][j])
            i--;
        else if(dp[i][j-1]==dp[i][j])
            j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;

}
