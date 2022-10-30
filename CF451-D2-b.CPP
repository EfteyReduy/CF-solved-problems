#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;

    int i, arr[n+1],s=1,e=1, sarr[n+1];
    bool t=true;
    arr[0]=sarr[0]=0;
    for(i=1; i<n+1; i++)
    {
        cin>>arr[i];
        sarr[i]=arr[i];
    }
    sort(sarr, sarr+n+1);
    for(i=1; i<n+1; i++)
    {
        if(arr[i]!=sarr[i])
        {
            s=i;
            break;
        }
    }for(i=n; i>0; i--)
    {
        if(arr[i]!=sarr[i])
        {
            e=i;
            break;
        }
    }
    reverse(arr+s, arr+e+1);

    for(i=1; i<=n; i++)
    {
        if(arr[i]!=sarr[i])
            break;
    }
    if(i==n+1)
        cout<<"yes\n"<<s<<" "<<e<<endl;
    else
        cout<<"no"<<endl;


}
