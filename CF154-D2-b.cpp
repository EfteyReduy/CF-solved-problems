#include<bits/stdc++.h>

using namespace std;
int arr[5001];
main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<=5000; i++)
    {
        arr[i]=0;
    }

    for(int i=0; i<n; i++)
    {
        arr[a[i]]++;
    }
    int ans=0;
    for(int i=1; i<=5000; i++)
    {
        int temp=0;
        for(int j=i; j<=2*i and j<=5000; j++)
        {
            temp+=arr[j];
        }
        ans=max(ans,temp);
    }
    cout<<n-ans<<endl;

}
