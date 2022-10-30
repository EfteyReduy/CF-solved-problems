#include<bits/stdc++.h>

using namespace std;


main()
{
    int n, ans=0;
    cin>>n;
    char arr[100];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<n-1; i++)
    {
        if(arr[i]=='0')
        {
            if(arr[i-1]=='1'&&arr[i+1]=='1')
            {
                //cout<<"here"<<i<<endl;
                ans++;
                i+=2;
            }
        }
    }
    cout<<ans<<endl;
}
