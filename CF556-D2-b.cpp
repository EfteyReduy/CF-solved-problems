#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    bool f=true;
    for(int i=0; i<n-2; i++)
    {
        for(int j=1; j<n-1; j++)
        {

            if(s[i][j]=='.')
            {
                s[i][j]='#';
                if(s[i+1][j]=='.')
                {
                    s[i+1][j]='#';
                }else f=false;
                if(s[i+2][j]=='.')
                {
                    s[i+2][j]='#';
                }else f=false;

                if(s[i+1][j-1]=='.')
                {
                    s[i+1][j-1]='#';
                }else f=false;
                if(s[i+1][j+1]=='.')
                {
                    s[i+1][j+1]='#';
                }else f=false;

                if(f==false)
                {
                    break;
                }
            }

        }
        if(f==false)
            break;

    }
    bool t=true;
    if(f)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i][j]=='.')
                {
                    cout<<"NO"<<endl;
                    t=false;
                    break;
                }
            }
            if(!t)
                break;
        }
        if(t)
        {
            cout<<"YES"<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
}
