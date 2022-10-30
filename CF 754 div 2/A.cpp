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
        int x=a+c;
        b=b*2;

        int y=abs(x-b);
        if(y%3==0)
        {
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }

    }
}
