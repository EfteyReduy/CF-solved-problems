#include<bits/stdc++.h>

using namespace std;

main()
{
    string s;
    cin>>s;
    int a=0, b=0;
    int j=0, k=s.length();
    int small[k+1], capital[k+1];
    small[0]=0;
    capital[k]=0;

    for(int i=0; i<k; i++)
    {
        if(s[i]>='a' and s[i]<='z')
            small[i+1]=small[i]+1;
        else
            small[i+1]=small[i];
    }

    for(int i=k-1; i>=0; i--)
    {
        if(s[i]>='A' and s[i]<='Z')
            capital[i]=capital[i+1]+1;
        else
            capital[i]=capital[i+1];
    }

    int ans=k;
    for(int i=0; i<=k; i++)
    {
        ans=min(ans, small[i]+capital[i]);
    }


    cout<<ans<<endl;
}
