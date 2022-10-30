#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int dp[sum+1];
    dp[0]=0;
    for(int i=1; i<=sum; i++)
        dp[i]=10000000;

    sort(arr, arr+n);
    for(int i=1; i<=sum; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-arr[j]<0)
            {
                break;
            }
            else{
                dp[i]=min(dp[i], dp[i-arr[j]]+1);
            }
        }
    }
    if(dp[sum]==10000000)
        cout<<-1<<endl;
    else
        cout<<dp[sum]<<endl;
}
