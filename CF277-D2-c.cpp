#include<bits/stdc++.h>


#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;

int main()
{
    long long n, cursor;
    cin>>n>>cursor;

    string s;
    cin>>s;

    long long i=(n-1)/2, j=(n/2);

    long long strt=0, ind=i;
    for(int x=0; x<=i; x++)
    {
        if(s[x]==s[n-x-1])
        {
            strt++;
        }
        else{
            break;
        }
    }
    for(int x=i; x>strt; x--)
    {
        if(s[x]==s[n-x-1])
        {
            i--;
            j++;
        }
        else{
            break;
        }
    }
    long long ans=0;
    for(int x=strt; x<=i; x++)
    {
        if(s[x]!=s[n-x-1])
        {
            int dif=abs(s[x]-s[n-x-1]);
            dif=min(dif, (26-dif));
            ans+=dif;
        }
    }

    if(ans==0)
    {
        cout<<ans<<endl;
    }
    else{
//        db(strt);
//        db(i);
//        db(j);
//        db(ind);
//        db(ans);
//        db(cursor);
//        db(cursor);
        cursor--;
        if(cursor>ind)
        {
            cursor=n-cursor-1;
        }

        ans+=(i-strt);
        if(cursor<i and cursor>strt)
        {
            ans+=(min(i-cursor, cursor-strt));
        }
        else if(cursor>i)
        {
            ans+=(cursor-i);
        }
        else if(cursor<strt)
        {
            ans+=(strt-cursor);
        }
        cout<<ans<<endl;
    }
}
