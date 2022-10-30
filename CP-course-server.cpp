#include<bits/stdc++.h>

using namespace std;

main()
{
    int t, n;
    cin>>n>>t;
    int total=0, ans=0, cur=0, arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int j=0;
    for(int i=0; i<n; i++)
    {

        total=total+arr[i];
        if(total>t)
        {
            ans=max(ans,cur);
            cur=0;
            total=total-arr[j];
            j++;
        }
        else{
            cur++;
        }
    }
    cout<<ans<<endl;

}
