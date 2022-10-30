#include<bits/stdc++.h>

using namespace std;

main()
{
    double inf=100000, n, x, y;
    cin>>n>>x>>y;
    set<double>s;
    for(int i=0; i<n; i++)
    {
        double a, b;
        cin>>a>>b;
        double hi=(x-a), run=(y-b);
        if(run==0)
        {
            s.insert(inf);
        }
        else{
            s.insert(hi/run);
        }
    }

    cout<<s.size()<<endl;
}
