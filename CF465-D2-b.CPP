#include<bits/stdc++.h>
using namespace std;

main()
{
    int n, i, j=0, ans=0;
    cin>>n;
    bool r=false;
    for(i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            ans=ans+j+1;
            j=0;
            r=true;
        }
        else if(r){
            j=1;

        }

    }
    cout<<ans<<endl;
}
