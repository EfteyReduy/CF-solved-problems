#include<bits/stdc++.h>

using namespace std;



main()
{
    int n, t;
    cin>>n>>t;

    string s1, s2;
    cin>>s1>>s2;

    int cou=0;
    for(int i=0; i<n; i++)
    {
        if(s1[i]==s2[i])
        {
            cou++;
        }
    }
    int men=(n-cou+1)/2;
    if(men>t)
        cout<<-1<<endl;
    else{
        string s="";
        char str[n];
        int skip=n-t;
        int rem=n-t;
        bool flp=true;

        for(int i=0; i<n; i++)
        {
            if(s1[i]==s2[i] and rem>0)
            {
                str[i]=s1[i];
                //t--;
                rem--;
            }
            else if(s1[i]==s2[i] and rem<=0)
            {
                    if(s1[i]!='z' and s2[i]!='z')
                    {
                        str[i]='z';
                    }
                    else if(s1[i]!='x' and s2[i]!='x')
                    {
                        str[i]='x';
                    }
                    else if(s1[i]!='y' and s2[i]!='y')
                    {
                        str[i]='y';
                    }

            }
        }

        skip=rem;
        for(int i=0; i<n; i++)
        {
            if(s1[i]!=s2[i])
            {
                if(skip>0)
                {
                    if(flp)
                    {
                        str[i]=s1[i];
                        flp=false;

                    }
                    else{
                        flp=true;
                        str[i]=s2[i];
                        skip--;
                    }
                }
                else{
                    if(s1[i]!='z' and s2[i]!='z')
                    {

                        str[i]='z';
                    }
                    else if(s1[i]!='x' and s2[i]!='x')
                    {
                        str[i]='x';
                    }
                    else if(s1[i]!='y' and s2[i]!='y')
                    {
                        str[i]='y';
                    }
                }
            }


        }

        for(int i=0; i<n; i++)
        {
            cout<<str[i];
        }
        //cout<<"possible"<<endl;
    }
}
