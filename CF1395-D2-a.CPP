#include<bits/stdc++.h>


using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long r, g, b, w;
        cin>>r>>g>>b>>w;
        long long c=min(r,min(g,b)), odd=0;
        (r%2!=0)?odd++:odd=odd ;
        (g%2!=0)?odd++: odd=odd;
        (b%2!=0)?odd++: odd=odd ;
        (w%2!=0)?odd++: odd=odd;
        if(odd<=1)
        {
            cout<<"yes"<<endl;
        }
        else if(odd==2)
        {
            cout<<"no"<<endl;
        }else if(c==0)
        {
            //cout<<c<<endl;
            cout<<"no"<<endl;
        }
        else
        {
            cout<<"yes"<<endl;
        }

    }
}
