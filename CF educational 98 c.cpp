#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ff=0, ss=0, ans=0;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                ff++;
            }
            else if(s[i]==')')
            {
                if(ff)
                {
                    ff--;
                    ans++;
                }
            }
            else if(s[i]=='[')
            {
                ss++;
            }
            else
            {
                if(ss)
                {
                    ss--;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
