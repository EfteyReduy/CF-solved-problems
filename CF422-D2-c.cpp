#include<bits/stdc++.h>

using namespace std;

main()
{
    long long n, x;
    cin>>n>>x;
    map<int, set<pair<int, int> > >mp;
    set<pair<int, int> >m, te;
    pair<pair<int, int>, int>p[n];
    for(int i=0; i<n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        te=mp[b-a+1];
        te.insert({a,c});
        p[i]={{a,b},c};
    }
}
