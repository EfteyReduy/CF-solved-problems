#include<bits/stdc++.h>

using namespace std;
long long ans=0;
long long f(string s, bool sml, int cou, int len, int i)
{

    if(i==len)
    {
        if(cou<4)
        {
            return 1;
        }

    }
    int x=s[i]-'0';
    if(sml)
    {
        ans+=(9*f(s,true,cou++,len,i+1));
        ans+=f(s, true, cou, len, i+1);
    }
    else{
        if(x==0)
        {
            ans+=(f(s, false, cou, len, i+1));
        }
        else{
            ans+=(f(s, true ,cou, len, i+1));

            for(int j=1; j<x; j++)
            {
                ans+=f(s, true, cou++, len, i+1);
            }
            ans+=f(s, false, cou++, len, i+1);
        }

    }
}






main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;
        int x=a.length();
        x--;
        while(a[x]=='0')
        {
            x--;
        }

        a[x]--;
        cout<<f(b, false, 0, b.length(), 0)-f(a, false, 0, a.length(), 0)<<endl;

    }
}
