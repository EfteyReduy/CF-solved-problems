#include<bits/stdc++.h>

using namespace std;


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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<string, set<pair<long long, long long>, cmpStruct > >mp;

        long long money;
        cin>>money;

        for(int i=0; i<n; i++)
        {
            string name, model;
            long long price, quality;
            cin>>name>>model>>price>>quality;

            mp[name].insert({quality,price});

        }

//        for(auto it:mp)
//        {
//
//            set<pair<long long , long long > >v=it.second;
//            //sort(v.begin(), v.end());
////            cout<<it.first<<endl;
////            for(auto i:v)
////            {
////                cout<<i.second<<" "<<i.first<<endl;
////            }
//            it.second=v;
//        }

        long long ans=0, lo=0, hi=20000000000;
        while(lo<=hi)
        {
           // cout<<"stack here at hi = "<<hi<<" and lo = "<<lo<<" and ans = "<<ans<<endl;
            long long rem=money, mid=(lo+hi)/2;
            bool pos=true;
            for(auto i:mp)
            {
                set<pair<long long, long long>, cmpStruct >v=i.second;
                pair<long long , long long>pp={mid, 0};
                auto it=lower_bound(v.begin(), v.end(), pp);
                if(it==v.end())
                {
//                    if(mid==3)
//                        cout<<"here at "<<i.first<<endl;
                    pos=false;
                    hi=mid-1;
                    break;
                }
                pair<long long, long long>p;
                p= *it;
                rem-=p.second;

                if(rem<0)
                {
                    pos=false;
                    hi=mid-1;
                    break;
                }

            }
            if(pos)
            {
                lo=mid+1;
                ans=max(ans, mid);
            }
            else{
                hi=mid-1;
            }
//            if(hi==lo)
//                break;
        }

        cout<<ans<<endl;



    }
}
