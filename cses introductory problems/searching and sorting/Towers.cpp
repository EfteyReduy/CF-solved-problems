#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, ans=0;
    cin>>n;
    set<pair<int, int> >s;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        pair<int, int>pp={a+1, 0};

        auto it=s.lower_bound(pp);
        if(it==s.end())
        {
            pair<int, int>p={a, i};
            s.insert(p);
            ans++;
        }
        else{
            s.erase(it);
            pp.first--;
            s.insert(pp);
        }

    }
    cout<<ans<<endl;
}
