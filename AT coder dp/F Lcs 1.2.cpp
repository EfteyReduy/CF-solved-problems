#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, m, dp[1000][1000];
string A, B, aa="";

ll f(ll i, ll j, string ss){
    if(i==n or j==m){
        cout<<ss<<endl;
        if(ss.length()>aa.length())
        {
            aa=ss;
        }
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans=0;
    if(A[i]==B[j]) {
        string ab=ss+A[i];
        ans = 1 + f(i+1, j+1, ss+=A[i]);
    }
    else ans = max(f(i+1, j, ss), f(i, j+1, ss));
    if(aa.length()<ss.length())
        aa=ss;
    return dp[i][j]=ans;
}

int main()
{
    string s, t;
    cin>>s>>t;
    n=s.length();
    m=t.length();
    A=s,B=t;
    memset(dp, -1, sizeof(dp));
    string fff="";
    ll a=f(0,0, fff);
    cout<<a<<endl;
    cout<<aa<<endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}
