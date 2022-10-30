#include<bits/stdc++.h>

using namespace std;

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
            int a;
            cin>>a;
            p[i]={a,i+1};
        }
        sort(p, p+n);

        set<int>s;
        string ans="";
        for(int i=0; i<n; i++)
        {
            s.insert(p[i].second);
            int sz=s.size();
            auto x=s.end();
            x--;
            auto y=s.begin();
            if((*x)-(*y)+1==sz)
            {
                ans+="1";
            }
            else{
                ans+="0";
            }

        }
        cout<<ans<<endl;

    }
}
