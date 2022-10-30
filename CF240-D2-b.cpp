#include<bits/stdc++.h>

using namespace std;

main()
{
    long long n, a, b;
    cin>>n>>a>>b;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        long long x;
        cin>>x;
        long long y=x;
        x=x*a;
        x=x/b;
        x=x*b;
        x=(x+a-1)/a;
        arr[i]=y-x;

    }

    for(int i=0; i<n ;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
