#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, k;
    cin>>n>>k;
    int arr[n], i;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(i=1; k-i>0; i++)
    {
        k=k-i;
    }
    cout<<arr[k-1]<<endl;
}
