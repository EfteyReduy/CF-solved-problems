#include<bits/stdc++.h>

using namespace std;
main()
{
    int n;
    cin>>n;
    string str, ans="", str2;
    cin>>str;
    str2=str;
    if(n%2==0)
    {
        int i;
        for(i=0; i<n; i++)
        {
            ans=str[i]+ans;
            i++;
            ans+=str[i];

        }
    }
    else
    {
        int i;
        ans=str[0];
        for(i=1; i<n; i++)
        {
            ans=str[i]+ans;
            i++;
            ans+=str[i];

        }
    }

    cout<<ans<<endl;

}
