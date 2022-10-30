#include<bits/stdc++.h>
using namespace std;


bool desc_pair(const std::pair<int, int> &p1, const std::pair<int, int> &p2)
{
    return std::max( p1.first, p2.first );
}
bool comparison(const pair<int,int> &a,const pair<int,int> &b){
    return a.first>b.first;
}

main()
{
    int n, a;
    cin>>n>>a;
    pair<int, int>ba[a];
    int b , j, i, c=0, ans=0;
    for(i=0; i<a; i++)
    {
        cin>>ba[i].second>>ba[i].first;
    }
    sort(ba, ba+a, comparison);
    for(i=0; i<a; i++)
    {
        if(n>=ba[i].second)
        {
            ans=ans+(ba[i].second*ba[i].first);
            n=n-ba[i].second;
        }
        else{
            ans+=ba[i].first*n;
            break;
        }
    }

    cout<<ans<<endl;
}
