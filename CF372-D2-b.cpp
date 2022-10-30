#include<bits/stdc++.h>

using namespace std;

main()
{
    string s;
    cin>>s;

    int n=s.length(), i=0, j=0;
    bool vis[26], has=0;
    if(n<26)
    {
        cout<<-1<<endl;
        return 0;
    }

    for( i=0; i<s.length()-25; i++)
    {
        for(j=0; j<26; j++)
        {
            vis[j]=0;
        }
        int uniq=0;
        for(j=i; j<i+26; j++)
        {
            int x=s[j]-'A';
            if(s[j]=='?')
            {
                uniq++;
            }
            else if(vis[x])
            {
                break;
            }
            else{
                vis[x]=1;
                uniq++;
            }
        }
        vector<char>v;
        if(uniq==26)
        {
            for(int k=0; k<26; k++)
            {
                if(!vis[k])
                {
                    v.push_back('A'+k);
                }
            }
            j=0;
            for(int k=i; k<i+26; k++)
            {
                if(s[k]=='?')
                {
                    s[k]=v[j];
                    j++;
                }
            }
            has=true;
            break;
        }
        else{
            uniq=0;
        }

    }
    if(has)
    {
        for(i=0; i<n; i++)
        {
            if(s[i]=='?')
            {
                s[i]='A';
            }
        }
        cout<<s<<endl;
    }
    else{
        cout<<-1<<endl;
    }

}
