#include<bits/stdc++.h>

using namespace std;
main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        string s;
        cin>>s;

        int n=s.length();
        bool found_greater=false;
        char great=s[n-1];
        string ans="";
        ans+=s[n-1];
        for(int i=n-2; i>=0; i--)
        {
            ans+=s[i];
            if(s[i]<s[i+1])
            {
                ans+=s[i];
                found_greater=true;

            }
            else if(s[i]==s[i+1] and found_greater and great>s[i])
            {
                ans+=s[i];
            }
            else{
                great=s[i];
            }

        }
        reverse(ans.begin(), ans.end());
        cout<<"Case #"<<cas<<": ";
        cout<<ans<<endl;
    }
}
