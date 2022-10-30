#include<bits/stdc++.h>
using namespace std;

main()
{
    string color="ROYGVBI" , c="GVBIROY";

    int i, n, a, r;
    cin>>n;
    a=n/7;
    r=n%7;
    for(i=0; i<a; i++)
    {
        cout<<color;
    }
    if(r<5)
        for(i=0; i<r; i++)
        {
            cout<<c[i];
        }

    else
        for(i=0; i<r; i++)
            cout<<color[i];
    cout<<endl;
}
