#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        if(b-a<a)
        {
            cout<<"-1 "<<"-1"<<endl;
        }
        else
        {
            cout<<a<<" "<<2*a<<endl;
        }
    }
}
