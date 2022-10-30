#include<bits/stdc++.h>


using namespace std;
struct cmpStruct {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        return lhs.second-lhs.first < rhs.second-rhs.first;
    }
};
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        pair<int, int>p[n];

        for(int i=0; i<n; i++)
        {
            int a, b;
            cin>>a>>b;
            p[i]={min(a, b), max(a, b)};
        }
        sort(p, p+n, cmpStruct());
        set<int>st;
        for(int i=0; i<n; i++)
        {
            st.insert(i+1);
        }
        for(int i=0; i<n; i++)
        {
            auto x=*st.lower_bound(p[i].first);
            cout<<p[i].first<<" "<<p[i].second<<" "<<x<<endl;
            st.erase(x);
        }
        cout<<endl;
    }
}
