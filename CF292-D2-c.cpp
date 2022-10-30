#include<bits/stdc++.h>
using namespace std;


main()
{
    int n;
    string s;
    cin>>n>>s;

    vector<int>ans;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='4')
        {
            ans.push_back(2);
            ans.push_back(3);
            ans.push_back(2);
        }
        else if(s[i]=='6')
        {
            ans.push_back(5);
            ans.push_back(3);
        }
        else if(s[i]=='9')
        {
            ans.push_back(7);
            ans.push_back(3);
            ans.push_back(2);
            ans.push_back(3);
        }
        else if(s[i]=='8')
        {
            ans.push_back(7);
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(2);
        }
        else if(s[i]!='1' and s[i]!='0')
        {
            ans.push_back((s[i]-'0'));
        }

    }
    sort(ans.begin(), ans.end(), greater<int>());

    int i=ans.size();

    for(i=0; i<ans.size(); i++)
    {
        if(ans[i]!=1 and ans[i]!=0)
            cout<<ans[i];
    }
    cout<<endl;

}
