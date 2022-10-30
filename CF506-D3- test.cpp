#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int j=s.length();
    j--;
    j=(n+1)/2;
    int cou=0,l=j;
    int m=0;
    for(int i=0; i<=n/2; i++)
    {

        if(s[m]==s[j] and j<n)
        {
            cou++;
            j++;
            m++;
        }
        else if(l<n-1)
        {
            cout<<"Testing : j="<<j<<" i= "<<i<<" m= "<<m<<endl;

            l++;
            j=l;
            cou=0;
            m=0;
            cout<<"Testing 2 : j="<<j<<" i= "<<i<<" m= "<<m<<endl;
        }
        else break;
    }
    if(j!=(s.length()))
        cou=0;
    n=n-cou;
    string sub;
    for(int i=0; i<n; i++)
    {
        sub+=s[i];
    }string ans;
    for(int i=0; i<k-1; i++)
    {
        ans+=sub;
    }
    //cout<<"sub is: "<<sub<<endl;
    cout<<ans<<s<<endl;;
}
