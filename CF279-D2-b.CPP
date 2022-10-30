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

int main()
{
    int n;
    cin>>n;
    int arr[n+10];
    map<int, int>mp;
    set<pair<int, int>, cmpStruct >s;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
        s.insert({a,b});
    }
    int a=0;
    for(int i=1; i<=n/2; i++)
    {
        auto it=s.lower_bound({a, 1});
        if(it!=s.end())
        {
            pair<int, int>p=*it;
            arr[(i*2)]=p.second;
            a=p.second;
        }
        else{

            break;
        }

    }
    int strt, ind;
    for(auto it:mp)
    {
        if(it.second==1)
        {
            ind=strt;
            strt=it.first;
        }
    }
    arr[1]=strt;
    auto iit=s.lower_bound({strt, 0});
    if(iit==s.end())
    {
        strt=ind;
    }
    else
    {
        pair<int , int>p=*iit;
        if(p.first!=strt)
            strt=ind;
    }

    a=0;

    for(int i=0; i<=n/2; i++)
    {
        arr[(i*2+1)]=strt;
        auto it=s.lower_bound({strt, 1});
        if(it!=s.end())
        {
            pair<int, int>p=*it;

            strt=p.second;
        }
        else{
            break;
        }

    }
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
