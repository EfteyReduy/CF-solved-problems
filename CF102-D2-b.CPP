#include<bits/stdc++.h>
using namespace std;

main()
{
    string s;
    cin>>s;
    int i=0, j, a=0, ans=0;
    for(i=0; i<s.length(); i++)
    {
        a=a+(s[i]-'0');
    }
    int n=a;
    a=0;
    if(s.length()>1)
        ans=1;
    while(n/10!=0)
    {

        while(n/10!=0)
        {
            a+=((n%10));
            i++;
            n=n/10;
        }
        a+=n;
        n=a;
        a=0;
        ans++;
        i=0;
    }
    cout<<ans<<endl;

}
