#include<bits/stdc++.h>

using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int x, y, z;
        int mex=max(a,max(b,c)), men=min(a,min(b,c));
        x=mex;
        y=men;
        z=a+b+c-x-y;
        if(x!=z)
            cout<<"no"<<endl;
        else
        {
            cout<<"yes"<<endl;
            cout<<y<<" "<<y<<" "<<x<<endl;
        }

    }
}
