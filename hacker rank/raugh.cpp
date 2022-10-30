#include<bits/stdc++.h>

using namespace std;


main()
{
    double p, t, a, q;
    cin>>p>>t>>a>>q;

    double total=p;
    int ans=0;
    if(t==0)
    {
        cout<<1<<endl;
    }
    else{
        while(total<q)
        {
            total+=total*(t/100);
            total+=a;
            cout<<"hare at mid = "<<ans+1<<" total population = "<<total<<endl;

            ans++;
        }
    }

    cout<<ans<<endl;

}
