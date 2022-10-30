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
    int cou=0;
    for(j; j<n; j++)
    {
        int k=j;
        for(int i=0; i<(n+1)/2; i++)
        {
            if(s[i]==s[k])
            {
                cou++;
                k++;
            }
            else
            {

                cou=0;
                break;
            }
        }
        if(k==n-1)
            break;
    }

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
