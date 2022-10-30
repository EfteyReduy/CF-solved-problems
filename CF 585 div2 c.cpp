#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    vector<pair<char, int> >p;
    int coua=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]!=t[i])
        {
            if(s[i]=='a')
                coua++;
            p.push_back({s[i],i+1});
        }
    }
    int ans=p.size();
    if(ans%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    ans/=2;
    if(coua%2)
    {
        cout<<ans+1<<endl;
        if(p[0].first=='a')
        {
            p[0].first='b';
        }
        else{
            p[0].first='a';
        }
        cout<<p[0].second<<" "<<p[0].second<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    sort(p.begin(), p.end());
    for(int i=0; i<p.size(); i+=2)
    {
        cout<<p[i].second<<" "<<p[i+1].second<<endl;
    }
}
