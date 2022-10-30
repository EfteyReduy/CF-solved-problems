#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);

    int ans[n], j=0, mid=(n)/2, i=0;
    int k=mid;
    while(i<n)
    {
        if(i%2)
        {
            ans[i]=arr[j];
            j++;
        }
        else{
            ans[i]=arr[k];
            k++;
        }
        i++;
    }
    int an=0;
    for(i=1; i<n-1; i++)
    {
        if(ans[i]<ans[i-1] and ans[i]<ans[i+1])
            an++;
    }
    cout<<an<<endl;
    for(i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
