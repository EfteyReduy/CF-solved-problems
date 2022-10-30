#include<bits/stdc++.h>


using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        int x, y;
        cin>>x>>y;
        bool pos=true;
        if(x<0)
        {
            if(abs(x)>y)
            {
                pos=false;
            }
        }
        if(y<0)
        {
            if(abs(y)>x)
            {
                pos=false;
            }
        }
        string s;
        cin>>s;
        int x1=0;

        int n=s.length();
        while(s[x1]=='?')
        {
            x1++;
        }
        if(n<2)
        {
            cout<<"Case #"<<cas<<": "<<0<<endl;
            continue;
        }
       // cout<<x1<<endl;
        if(x1==n)
        {
           // cout<<"HERE"<<endl;
            cout<<"Case #"<<cas<<": "<<min(0, ((x+y)*((n-1)/2))+(min(x,y)*(n%2==0)))<<endl;
            continue;
        }
        if(pos)
        {

            for(int i=x1-1; i>=0; i--)
            {
                if(s[i]=='?')
                {
                    if(s[i+1]=='C')
                    {
                        s[i]='C';
                    }
                    else{
                        s[i]='J';
                    }
                }
            }
            for(int i=x1; i<n; i++)
            {
                if(s[i]=='?')
                {
                    if(s[i-1]=='C')
                    {
                        s[i]='C';
                    }
                    else{
                        s[i]='J';
                    }
                }
            }
        }
        else
        {

            for(int i=x1-1; i>=0; i--)
            {
                if(s[i]=='?')
                {
                    if(s[i+1]=='J')
                    {
                        s[i]='C';
                    }
                    else{
                        s[i]='C';
                    }
                }
            }
            for(int i=x1; i<n; i++)
            {
                if(s[i]=='?')
                {
                    if(s[i-1]=='J')
                    {
                        s[i]='C';
                    }
                    else{
                        s[i]='J';
                    }
                }
            }
        }
        int ans=0;
        //cout<<s<<endl;
        for(int i=1; i<n; i++)
        {
            if(s[i]!=s[i-1])
            {
                if(s[i]=='J')
                {
                    ans+=x;
                }
                else{
                    ans+=y;
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}
