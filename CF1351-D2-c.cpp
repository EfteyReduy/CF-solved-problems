#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>s;
        set<pair<pair<int, int>, pair<int, int> > >p;
        int x=0, y=0, ans=0;
        pair<int, int> p1={0,0}, p2;
        //p.insert(make_pair(x,y));
        for(int i=0; i<s.length(); i++)
        {
            p2=p1;
            int X=x, Y=y, a=p.size();
            if(s[i]=='N')
                p2.first++;
            else if(s[i]=='S')
                p2.first--;
            else if(s[i]=='E')
                p2.second++;
            else
                p2.second--;

            if(p.find({p1, p2})!=p.end() or p.find({p2, p1})!=p.end())
                ans+=1;
            else
                ans+=5;

            p.insert(make_pair(p1, p2));

            p1=p2;
        }
        cout<<ans<<endl;
    }
}
