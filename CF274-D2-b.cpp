#include<bits/stdc++.h>

using namespace std;
///comparison structure to use customize set.............
struct cmpStruct {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first < rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

main()
{
    int n, k;
    cin>>n>>k;
    long long total=0;
    set<pair<int, int> , cmpStruct>s;
    for(int i=0; i<n; i++)
    {
        long long a;
        cin>>a;
        total+=a;
        s.insert({a,i+1});
    }
//
//    for(auto i:s)
//    {
//        pair<int, int>p=(i);
//        cout<<p.first<<" "<<p.second<<endl;
//    }

    vector<pair<int, int>>ans;
    if(n== 1)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }

    for(int i=0; i<k; i++)
    {
        pair<int , int>p, q;
        auto it=s.begin();
        p=(*it);
        s.erase(it);
        it=s.end();
        it--;

        q=(*it);
        s.erase(it);

        if(q.first>p.first+1)
        {
            p.first+=1;
            q.first-=1;
            ans.push_back({q.second, p.second});
            s.insert(p);
            s.insert(q);
        }
        else{
            s.insert(p);
            s.insert(q);
            break;
        }


    }
    pair<int , int>p, q;
    auto it=s.begin();
    p=(*it);
    it=s.end();
    it--;

    q=(*it);

    cout<<q.first-p.first<<" "<<ans.size()<<endl;

    for(auto i:ans)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }


}
