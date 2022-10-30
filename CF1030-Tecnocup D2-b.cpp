#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, d, m;
    cin>>n>>d>>m;

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        int c1=y-x;
        int c2=y+x;

        if(c1>=-d and c1<=d and c2>=d and c2<=(2*n)-d)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
