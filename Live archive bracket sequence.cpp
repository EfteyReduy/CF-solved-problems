#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    for(int ii=1; ii<=t; ii++)
    {
        string s;
        cin>>s;
        stack<pair<char, int> >st;
        int n=s.length();
        vector<int>ans(n,0);

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' or s[i]=='[' or s[i]=='{' or s[i]=='<')
            {
                st.push({s[i], i});
            }
            else if(!st.empty()){
                auto it=st.top();
                st.pop();
                if(s[i]==it.first+1 or s[i]==it.first+2 )
                {
                    ans[it.second]=i-it.second+1;
                }
                else{
                    while(!st.empty())
                    {
                        st.pop();
                    }
                }
            }
        }
        for(int i=n-1; i>=0; i--)
        {
            if(ans[i] and i+ans[i]<n)
            {
                ans[i]+=ans[(i+ans[i])];
            }
        }
        cout<<"Case "<<ii<<":"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<endl;
        }
        //cout<<endl;
    }
}
