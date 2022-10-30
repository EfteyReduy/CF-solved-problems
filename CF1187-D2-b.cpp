
#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    string st;
    cin>>n;
    cin>>st;
    int t;

    vector<int>alp[26];
    for(int i=0; i<st.size(); i++)
    {
        int p=st[i]-'a';
        alp[p].push_back(i);
    }
    cin>>t;
    int ans=0;
    while(t--)
    {
        ans=0;
        string s;
        int a[26]={0};
        cin>>s;
        for(int i=0; i<s.size(); i++)
        {
            int x=s[i]-'a';
            a[x]++;
        }

        for(int i=0; i<26; i++)
        {

            if(a[i])
            {
                int x=a[i];
                ans=max(ans,alp[i][x-1]);
            }
        }
        cout<<ans+1<<endl;
    }
}
