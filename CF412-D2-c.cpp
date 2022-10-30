#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    string s[n], ans;
    for(int i=0; i<n; i++)
        cin>>s[i];

    for(int i=0; i<s[0].length(); i++)
    {
        bool t=true;
        set<char> ch;
        char it;
        for(int j=0; j<n; j++)
        {
            if(s[j][i]!='?')
            {
                it=s[j][i];
            }


            if(s[j][i]!='?')
                ch.insert(s[j][i]), it=s[j][i];
            if(ch.size()>1)
            {
                t=false;
                ch.clear();
                break;
            }
        }
        if(t)
        {
//            set<char> :: iterator it=ch.begin();
            if(ch.size())
                ans+=it;
            else
                ans+='b';
        }
        else
            ans+='?';

    }
    cout<<ans<<endl;
}
