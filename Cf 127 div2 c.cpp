#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    int x=1, ans=1, j=1;
    if(n==3)
    {
        cout<<5<<endl;
        return 0;
    }
    while(x<n)
    {
        x+=(4*j);
        j++;
        ans+=2;
    }
    cout<<ans<<endl;

}
