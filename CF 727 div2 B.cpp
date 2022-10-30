#include<bits/stdc++.h>
using namespace std;

main()
{
    int n, t;
    cin>>n>>t;
    string s;
    cin>>s;

    int arr[n+1];
    for(int i=0; i<n; i++)
    {
        int a=s[i]-'a'+1;
        arr[i+1]=a;
    }
    for(int i=1; i<=n; i++)
    {
        arr[i]+=arr[i-1];
    }
    while(t--)
    {
        int l, r;
        cin>>l>>r;
        l--;
        cout<<arr[r]-arr[l]<<endl;
    }
}
