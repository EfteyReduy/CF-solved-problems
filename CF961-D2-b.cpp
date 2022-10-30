#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, k;
    cin>>n>>k;
    int arr[n], pos[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int st=0,tot=0;
    for(int i=0; i<n; i++)
    {
        cin>>pos[i];
        if(pos[i]==1)
        {
            tot+=arr[i];
        }
    }
    for(int i=0; i<k; i++)
    {
        if(pos[i]==0)
        {
            st+=arr[i];
        }
    }
    int a=st;
    for(int i=k; i<n; i++)
    {

        if(pos[i]==0)
            a=a+arr[i];

        if(pos[i-k]==0)
        {
            a=a-arr[i-k];
        }

        st=max(a,st);

    }
    cout<<st+tot<<endl;

}
