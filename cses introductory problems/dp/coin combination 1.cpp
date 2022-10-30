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
    int dp[x+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    sort(arr, arr+n);
    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[j]<=i)
            {
                dp[i]+=(dp[i-arr[j]]);
                dp[i]=dp[i]%(1000000007);
            }
            else{
                break;
            }
        }
    }
    cout<<dp[x]<<endl;
}
