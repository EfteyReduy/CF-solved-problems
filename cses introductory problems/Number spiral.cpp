#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--){
        long long x, y;
        cin>>x>>y;

        long long ans=0;

        if(x>y)
        {
            if(x%2)
            {
                ans=(x-1)*(x-1)+y;
            }
            else{
                ans=(x*x)-y+1;
            }
        }
        else{
            if(y%2)
            {
                ans=(y*y)-x+1;
            }
            else
            {
                ans=(y-1)*(y-1)+x;
            }
        }
        cout<<ans<<endl;
    }
}
