#include<bits/stdc++.h>

using namespace std;

main()
{
    double a, b, c, d, x, y;

    cin>>a>>b>>c>>d;

    x=a/c, y=b/d;

    if(x>y)
    {
        swap(a,b);
        swap(c,d);
    }
    int i=(b*c)-(a*d), j=b*c;

    int z=__gcd(i,j);
    cout<<(i/z)<<"/"<<(j/z)<<endl;

}
