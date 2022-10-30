#include<bits/stdc++.h>
#define INF 10000000000
using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n], crr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>crr[i];
    }

    long long a=INF, b=INF, c=INF, ans=INF;

    for(int j=1; j<n-1; j++)
    {
        b=crr[j];
        for(int i=0; i<j; i++)
        {
            if(arr[i]<arr[j])
            {
                if(crr[i]<a)
                    a=crr[i];
            }
        }
        for(int i=j+1; i<n; i++ )
        {
            if(arr[i]>arr[j])
            {
                if(crr[i]<c)
                    c=crr[i];
            }
        }
        ans=min(ans,a+b+c);
        a=INF, b=INF, c=INF;
    }
    if(ans>=INF)
    {
        cout<<-1<<endl;
    }
    else
        cout<<ans<<endl;


}
