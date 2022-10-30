#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    long long vec[n];
    long long svec[n];
    for(int i=0; i<n; i++)
    {
        long long a;
        cin>>a;
        vec[i]=a;
        svec[i]=a;
    }


    sort(svec, svec+n);

    int m;
    cin>>m;
    int  t[m], l[m], r[m];
    long long ans=0;

    for(int i=1; i<n; i++)
    {
        vec[i]+=vec[i-1];
    }
    for(int i=1; i<n; i++)
    {
        svec[i]+=svec[i-1];
    }

    for(int i=0; i<m; i++)
    {
        cin>>t[i]>>l[i]>>r[i];
    }
    for(int i=0; i<m; i++)
    {
        if(t[i]==1&&l[i]!=1)
            ans=vec[r[i]-1]-vec[l[i]-2];
        else if(t[i]==2&&l[i]!=1)
            ans=svec[r[i]-1]-svec[l[i]-2];
        if(l[i]==1&&t[i]==1)
            ans=vec[r[i]-1];
        else if(l[i]==1 && t[i]==2)
            ans=svec[r[i]-1];


        cout<<ans<<endl;
        ans=0;
    }
}
