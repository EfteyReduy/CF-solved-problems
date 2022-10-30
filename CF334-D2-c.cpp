#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int a=-1, b=-1;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1])
        {
            a=i;
            break;
        }
    }

    for(int i=n-2; i>=0; i--)
    {
        if(s[i]==s[i+1])
        {
            b=i;
            break;
        }
    }


    if(n<4 or a<0)
    {
        cout<<n<<endl;
        return 0;
    }

    if(b<a)
    {
        b=n-1;
    }
    for(int i=a; i<=b; i++)
    {
        if(s[i]=='1')
        {
            s[i]='0';
        }
        else{
            s[i]='1';
        }
    }
    int ans=0;
    ans++;
    char bgn=s[0];
    for(int i=1; i<n; i++)
    {
        if(s[i]==bgn)
        {
            continue;
        }
        else{
            ans++;
            bgn=s[i];
        }
    }
    cout<<ans<<endl;

}
