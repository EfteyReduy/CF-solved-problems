#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll mod=1000000007;
ll ncr[1001][1001]={0};
void nCrTable(){
    for(int i=0; i<1001; i++)
    {
        ncr[0][i]=1;
        ncr[i][0]=1;
    }

    for(int i=1; i<1001; i++)
    {
        for(int j=1; j<1001; j++)
        {
            ncr[i][j]=ncr[i-1][j]+ncr[i][j-1];
            ncr[i][j]%=mod;
        }
    }
}

ll nCr(int n, int r){

    int x=min(r, n-r);
    return ( ncr[n-x][x]);
}


main()
{
    int n;
    cin>>n;

    nCrTable();
    long long arr[n], tot=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        tot+=arr[i];
    }
    ll ans=1;
    for(int i=n-1; i>0; i--)
    {
        int x=min(arr[i]-1, tot-arr[i]);

        ans*=(ncr[tot-x-1][x]);

        tot-=arr[i];
        ans%=mod;
    }
    cout<<ans<<endl;
}
