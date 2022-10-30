#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    string s, str;
    cin>>s;


    int ans=0;
    int mn=s.length()+1;
    str=s[0];
    for(int i=1; i<n; i++)
    {
        char cc=s[i];
        if(s[i]==s[i-1])
        {
            if(s[i]=='R')
            {
                if(i+1<n and s[i+1]=='B')
                {
                    s[i]='G';
                    cc='G';
                }else{
                    s[i]='B';
                    cc='B';
                }
            }
            else if(s[i]=='G')
            {
                if(i+1<n and s[i+1]=='B')
                {
                    cc='R';
                    s[i]='R';
                }else{
                    s[i]='B';
                    cc='B';
                }
            }
            else if(s[i]=='B')
            {
                if(i+1<n and s[i+1]=='R')
                {
                    s[i]='G';
                    cc='G';
                }else{
                    s[i]='R';
                    cc='R';
                }
            }
            ans++;
        }
        str+=cc;

    }
    cout<<ans<<endl;
    cout<<str;
    cout<<endl;

}

