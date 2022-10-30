#include<bits/stdc++.h>



using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x, y;
        cin>>x>>y;
        if(x>y)
        {
            cout<<x-y<<endl;
        }
        else{
            int cou=0;
            if((y-x)%2!=0)
            {
                cou=2;
            }
            cout<<((y-x)/2)+cou<<endl;
        }
    }
}
