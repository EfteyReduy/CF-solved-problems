#include<bits/stdc++.h>

using namespace std;

main()
{
    string s, t, rem="";
    cin>>s>>t;
    map<char, int>mp;
    for(int i=0; i<t.length(); i++)
    {
        mp[t[i]]++;
    }
    int y=0, w=0;

    for(int i=0; i<s.length(); i++)
    {
        if(mp[s[i]]>0)
        {
            mp[s[i]]--;
            y++;
        }
        else
        {
            rem+=s[i];
        }
    }

    int dif='a'-'A';
    for(int i=0; i<rem.length(); i++)
    {
        if(rem[i]<'a')
        {
            rem[i]+=dif;
            if(mp[rem[i]]>0)
            {
                mp[rem[i]]--;
                w++;
            }
        }
        else{
            rem[i]-=dif;
            if(mp[rem[i]]>0)
            {
                mp[rem[i]]--;
                w++;
            }

        }

    }

    cout<<y<<" "<<w<<endl;
}
