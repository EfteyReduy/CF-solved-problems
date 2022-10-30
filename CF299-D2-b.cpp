#include<bits/stdc++.h>


using namespace std;


main()
{
    string s;
    cin>>s;
    int n=s.length();
    long long ans=0;

    ans=pow(2,(n))-1;

    for(int i=n-1; i>=0; i--)
    {
        if(s[i]=='7')
        {
            ans+=pow(2, (n-i-1));
        }
    }
    cout<<ans<<endl;


}
