#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }


    map<int, vector<int> >mp;

    for(int i=0; i<n; i++)
    {
        mp[arr[i]].push_back(i);
    }
    vector<pair<int, int> >p;
    for(auto i:mp)
    {
        vector<int>v;
        v=i.second;

        if(v.size()<3)
        {
            if(v.size()==1)
            {
                p.push_back({i.first, 0});
            }
            else
            {
                p.push_back({i.first, abs(v[0]-v[1])});
            }

        }
        else
        {
            int j=0, dif=abs(v[0]-v[1]);
            for( j=1; j<v.size(); j++)
            {
                if(abs(v[j]-v[j-1])!=dif)
                    break;
            }
            if(j==v.size())
            {
                p.push_back({i.first, dif});
            }
        }

    }
    cout<<p.size()<<endl;
    for(int i=0; i<p.size(); i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }

}
