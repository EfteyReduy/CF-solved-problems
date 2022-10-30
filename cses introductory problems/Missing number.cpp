#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        arr[i]=0;
    for(int i=0; i<n-1; i++)
    {
        int a;
        cin>>a;
        arr[a-1]=1;
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
            cout<<i+1<<endl;
    }

}
