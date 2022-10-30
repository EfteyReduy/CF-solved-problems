#include<bits/stdc++.h>
using namespace std;

main()
{
    string s;
    cin>>s;
    int n=s.length();
    int cou=1, ans=0;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1])
        {
            cou++;
        }
        else{
            ans=max(ans,cou);
            cou=1;
        }
    }

    cout<<max(cou,ans)<<endl;

}
