#include<bits/stdc++.h>
using namespace std;


main()
{
    long long a, b, c, d, ans=0;
    char ch[3];
    cin>>a>>b>>c>>d;
    long long arr[4]={a,b,c,d};
    cin>>ch[0]>>ch[1]>>ch[2];
    sort(arr,arr+4);
    if(ch[0]=='*')
    {
        ans=arr[0]*arr[3];
        arr[3]=ans;
        sort(arr+1, arr+4);
        if(ch[1]=='*')
        {
            ans=(arr[1]*arr[2]);
            if(ch[2]=='*')
            {
                ans=(ans*arr[3]);
            }
            else{
                ans=(ans+arr[3]);
            }
        }
        else{
            ans=(arr[2]+arr[3]);
            arr[2]=ans;
            if(ch[2]=='*')
            {
                ans=(arr[2]*arr[1]);
            }
            else{
                ans=(arr[2]+arr[1]);
            }
        }
    }
    else{
        ans=arr[3]+arr[2];
        arr[2]=ans;
        sort(arr,arr+3);

        if(ch[1]=='*')
        {
            ans=(arr[0]*arr[1]);
            arr[1]=ans;
            if(ch[2]=='*')
            {
                ans*=arr[2];
            }
            else{
                ans+=arr[2];
            }

        }
        else{
            ans=(arr[2]+arr[1]);
            arr[1]=ans;
            if(ch[2]=='*')
            {
                ans*=arr[0];
            }
            else{
                ans+=arr[0];
            }
        }

    }
    cout<<ans<<endl;
}
