#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int j=0;
        while(s[j]=='L')
            j++;
        int bgn=j;
        j=s.length();
        j--;
        int i=bgn;
//        while(s[j]=='L')
//            j--, bgn++;
//
        int coul=0;
        for( ; i<n; i++)
        {
            if(s[i]=='L')
            {
                coul++;
                int co=0, x=i;
                while(s[i]=='L' and i<n)
                    co++, i++;
                int cou=co;
                if(co<=k)
                {
                    while(cou--)
                    {
                        s[x]='W';
                        x++;
                    }
                    k=k-co;
                }
//                else{
//                    while(k--)
//                    {
//                        s[x]='W';
//                        x++;
//                    }
//                }
            }
        }
        int ans=0;
        for(i=0; i<n; i++)
        {
            if(s[i]=='W')
            {
                if(i>0 and s[i-1]=='W')
                    ans+=2;
                else
                    ans+=1;
            }
        }
        if(k>0)
        {

            int x=min(k, bgn);
            ans+=(x*2);
            if(coul==n)
                ans-=1;

        }
        cout<<ans<<endl;
    }
}
