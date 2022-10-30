#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct cmpStruct{
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first < rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

int main() {

    int n;
    cin>>n;
    vector<pair<int, int> > p;
    vector<int>v;
    map<int, int>mp;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        if(mp.find(a) != mp.end())
        {
            mp[a] = min(mp[a], b);
        }
        else{
            mp[a] = b;
        }
    }

    for(auto it:mp)
    {
        p.push_back(it);
        v.push_back(it.first);
    }

    sort(p.begin(), p.end(), cmpStruct() );
    sort(v.begin(), v.end());

    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        auto it = lower_bound(v.begin(),v.end(), x);
        int ans;
        int val = x+5;

        if(it == v.end())
        {
            it--;
            ans = mp[*it];
        }
        else{
            ans = mp[*it];
            val = *it-x;

            if(it!=v.begin())
            {
                it--;
                if(val>(abs(x- (*it)))){
                    ans = mp[*it];
                }
                else if(val == abs(x-(*it))){
                    ans = min(ans, mp[*it]);
                }
            }
        }


        cout<<ans<<endl;
    }

    return 0;
}
