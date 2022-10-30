#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    long long arr[n], sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++)
    {

        if(sum+1<arr[i])
        {
            break;
        }
        sum+=arr[i];
    }
    cout<<sum+1<<endl;
}
