#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, r;
    cin>>n>>r;
    int arr[n], one=0, zero=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i])
            one++;
        else if(!arr[i])
            zero++;
    }
    int ans=1;

    int p=r;


    while(p<=n)
    {
        int s=p+r;
        p=r+s-1;
        ans++;
    }

    for(int i=0; i<n; i++)
    {
        i=i+(i-r+2)+(i+r);
        //ans++;
    }
    if(ans>one)
    {
        cout<<-1<<endl;
    }
    else
        cout<<ans<<endl;
}
