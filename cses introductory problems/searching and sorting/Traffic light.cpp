#include<bits/stdc++.h>

using namespace std;


main()
{
    int n, x;
    cin>>x>>n;
    set<int>s;
    s.insert(0);
    s.insert(x+1);
    set<pair<int, int> >st, dis;
    pair<int, int>p;
    p={x, 0};
    dis.insert(p);
    p={0, x+1};
    st.insert(p);

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        p={0, a};
        auto it=st.lower_bound(p);
        p=(*it);
        int strt=p.first, ind=p.second;
        st.erase(it);
        p={strt,a};
        st.insert(p);
        p={a, ind};
        st.insert(p);

        int tempdis=ind-strt-1;

        p={tempdis,0};
        it=dis.lower_bound(p);
        dis.erase(it);
        p={a-strt, i+n};
        dis.insert(p);
        p={ind-a, i};

        it=dis.end();
        it--;
        p=(*it);
        cout<<p.first<<endl;
        cout<<"stack"<<endl;

    }

}
