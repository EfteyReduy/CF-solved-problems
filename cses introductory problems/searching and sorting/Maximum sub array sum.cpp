#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    long long ans=arr[0],mex=arr[0], temp=0, cou=0;
    for(int i=0; i<n; i++)
    {

        temp+=arr[i];
        if(temp<0)
        {
            temp=0;
            cou++;
        }
        mex=max(mex, arr[i]);
        ans=max(ans, temp);
    }

    if(cou==n)
    {
        cout<<mex<<endl;

    }
    else
        cout<<ans<<endl;
}
