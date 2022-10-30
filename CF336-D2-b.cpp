#include<bits/stdc++.h>


using namespace std;



main()
{
    string s, t;
    cin>>s>>t;

    int n=s.length(), m=t.length();
    int one[n], zero[n];
    one[0]=0;
    zero[0]=0;
    if(s[0]=='1')
        one[0]++;
    else
    {
        zero[0]++;
    }
    for(int i=1; i<n; i++)
    {
        one[i]=one[i-1];
        zero[i]=zero[i-1];
        if(s[i]=='1')
            one[i]++;
        else
            zero[i]++;
    }
    long long ans=0;
    for(int i=0; i<m; i++)
    {
        if(i<n)
        {
            if(t[i]=='0')
            {
                if(m-i<n)
                {

                }
                ans+=one[i];
            }
            else
                ans+=zero[i];
        }
        else
        {
            if(t[i]=='0')
            {
                ans+=one[n-1];
            }
            else{
                ans+=zero[n-1];
            }
        }
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    one[0]=0;
    zero[0]=0;
    if(s[0]=='1')
        one[0]++;
    else
    {
        zero[0]++;
    }
    for(int i=1; i<n; i++)
    {
        one[i]=one[i-1];
        zero[i]=zero[i-1];
        if(s[i]=='1')
            one[i]++;
        else
            zero[i]++;
    }

    for(int i=0; i<n; i++)
    {
        if(t[i]=='0')
            ans+=one[i];
        else{
            ans+=zero[i];
        }
    }

    if(m<2*n)
        cout<<ans<<endl;

    int ones[m], zeros[m];


}
