#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    string sequence;
    cout<<"Enter the binary sequence : ";
    cin>>sequence;

    n=sequence.length();

    map<string, int>mp;
    vector<pair<int, int> >p;
    vector<pair<int, string> >q;

    mp["0"]=1;
    mp["1"]=2;
    p.push_back({1, 0});
    p.push_back({2, 1});

    int j=3;

    for(int i=0; i<n; i)
    {
        string st="";
        st+=sequence[i];
        i++;
        int prefix=mp[st];
        while(mp[st] and i<n)
        {
            st+=sequence[i];
            i++;
            if(mp[st])
            {
                prefix=mp[st];
            }
        }
        if(i<=n and !mp[st]){
            mp[st]=j;
            prefix*=2;
            if(sequence[i-1]=='1')
                prefix+=1;
            p.push_back({j, prefix});
            j++;
        }
    }
    int mex_len=0;
    for(auto it:mp)
    {
        q.push_back({it.second, it.first});
        //cout<<it.first<<" "<<it.second<<endl;
        int x=it.first.length();
        mex_len=max(mex_len, x);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    for(int i=0; i<p.size(); i++)
    {
        cout<<p[i].first<<" ---> "<<q[i].second<<" ---> "<<bitset<5>(p[i].second)<<endl;
    }
}
