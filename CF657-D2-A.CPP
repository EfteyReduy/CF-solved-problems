#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, cou=0, cou2=0, a, b, s;
        cin>>n;
        string str, match="abacaba";
        cin>>str;
        bool f=false;
        for(int i=0; i<n-6; i++)
        {
            if(str[i]=='a'||str[i]=='?'){
                a=i;
                for(int j=0; j<7; j++)
                {
                    if(str[i]==match[j])
                    {
                        i++;
                    }else if(str[i]=='?')
                    {
                        i++;
                        f=true;
                    }
                    else{
                        break;
                    }
                    b=j;

                }
                i=a;
                if(b==6&&f==true)
                {
                    cou++;
                    f=false;
                    s=a;
                }
                else if(b==6&&f==false)
                {
                    cou2++;
                }
            }
        }
        if(cou2>1)
        {
            cout<<"no"<<endl;
            continue;
        }
        else if(cou2==1)
        {
            cout<<"yes"<<endl;
            for(int i=0; i<n; i++)
            {
                if(str[i]=='?')
                {
                    cout<<'d';
                }
                else
                    cout<<str[i];
            }
            cout<<endl;
        }
        else if(cou==0)
        {
            cout<<"no"<<endl;
            continue;

        }
        else if(cou>0) {
            cout<<"yes"<<endl;
            for(int i=0; i<s; i++)
            {
                if(str[i]=='?')
                    cout<<'d';
                else
                    cout<<str[i];
            }
            cout<<match;
            for(int i=s+7; i<n; i++)
            {
                cout<<str[i];
            }
            cout<<endl;
        }

    }
}
