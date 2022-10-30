#include<bits/stdc++.h>


using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    int arr[n];
    for(int i=0; i<n; i++)arr[i]=0;
    for(int i=0;i<m; i++)
    {
        int a, c, b;
        cin>>a>>b>>c;
        arr[a]+=c;
        arr[b]-=c;
    }
    int ans=0, ans2=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            ans+=arr[i];
        }
        else
        {
            ans2+=abs(arr[i]);
        }
    }
    cout<<max(ans,ans2)<<endl;
}
