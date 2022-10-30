#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

ll n, m, a[1000], dp[1000][1000];

ll f(ll pos, ll sum){
    if(pos==n){
        if(sum==m) return 1;
        else return 0;
    }
    if(dp[pos][sum]!=-1) return dp[pos][sum];

    ll ans1=0, ans2=0;

    if(sum+a[pos]<=m) ans1 = f(pos+1, sum+a[pos]);
    ans2 = f(pos+1, sum);

    dp[pos][sum]= ans1 + ans2;
}

ll fun(ll pos, ll sum){

    if(sum==0)
        return 1;
    if(pos<=0)
    {
        return 0;
    }

    if(dp[pos][sum]!=-1)
    {
        return dp[pos][sum];
    }
    if(a[pos]<sum)
    {
        return dp[pos][sum]=fun(pos-1,sum);
    }
    else
    {
        return dp[pos][sum]=(dp[pos-1][sum]=fun(pos-1, sum))+(dp[pos][sum-a[pos]]=fun(pos, sum-a[pos]));
    }


}

int main()
{
    while(1){
        memset(dp, -1, sizeof(dp));
        cout<<"Enter number of elements in the array : ";
        cin>>n;
        cout<<"Enter elements in the array : "<<endl;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }

        cout<<"Enter target sum : ";
        cin>>m;
        cout<<fun(n, m)<<endl;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                cout<<dp[i][j]<<" ";
                dp[i][j]=-1;
            }
            cout<<endl;
        }
        cout<<f(0, 0)<<endl;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                cout<<dp[i][j]<<" ";
                dp[i][j]=-1;
            }
            cout<<endl;
        }
    }
}

