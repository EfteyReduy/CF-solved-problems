#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long n, p, q, r;
    cin>>n>>p>>q>>r;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    long long pre[n][2], pos[n][2];
    pre[0][0]=pre[0][1]=arr[0];
    pos[n-1][0]=pos[n-1][1]=arr[n-1];

    for(int i=1; i<n; i++)
    {
        pre[i][0]=min(pre[i-1][0], arr[i]);
        pre[i][1]=max(pre[i-1][1], arr[i]);
    }

    for(int i=n-2; i>=0; i--)
    {
        pos[i][0]=min(pos[i+1][0], arr[i]);
        pos[i][1]=max(pos[i+1][1], arr[i]);
    }
    long long ans=-4e18;
   // cout<<ans<<endl;

    for(int i=0; i<n; i++)
    {
        long long x, y, z;
        if(p<0)
        {
            x=pre[i][0];
        }
        else{
            x=pre[i][1];
        }
        if(r<0)
        {
            z=pos[i][0];
        }
        else{
            z=pos[i][1];
        }
        long long temp=(p*x)+(q*arr[i])+(r*z);
        //cout<<temp<<endl;
        ans=max(ans,temp);
    }
    cout<<ans<<endl;


}
