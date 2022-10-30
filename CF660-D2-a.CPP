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
        if(n<=30)
        {
            cout<<"no"<<endl;
        }
        else
        {
            cout<<"yes"<<endl;
            int a=n-6-10-14;
            if(a==14||a==10||a==6)
                cout<<6<<" "<<10<<" "<<15<<" "<<a-1<<endl;
            else
                cout<<6<<" "<<10<<" "<<14<<" "<<a<<endl;
        }
    }
}
