#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
           // a=abs(a);
            a=a%k;
            a+=k;
            a%=k;
            arr[i]=a;
        }
        int dp[n+1][k+1];
        memset(dp, -1, sizeof(dp));
        int bgn=arr[0];
        bgn+=k;
        bgn%=k;
        dp[0][bgn]=1;

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                if(dp[i-1][j]==1)
                {
                    int a=j+arr[i];
                    a%=k;
                    a+=k;
                    a%=k;
                    dp[i][a]=1;
                    a=j-arr[i];
                    a%=k;
                    a+=k;
                    a%=k;
                    dp[i][a]=1;
                }
            }
        }
        if(dp[n-1][0]==1)
        {
            cout<<"Divisible"<<endl;
        }
        else
        {
            cout<<"Not divisible"<<endl;
        }
    }
    return 0;
}
