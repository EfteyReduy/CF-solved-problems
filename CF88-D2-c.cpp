#include<bits/stdc++.h>


using namespace std;


main()
{
    int a, b;
    cin>>a>>b;
    bool d=true;
    if(a>b)
        d=false, swap(a,b);
    int x=__gcd(a,b);
    a=a/x;
    b=b/x;

    if(b-a==1)
        cout<<"Equal"<<endl;
    else{
        if(d)
            cout<<"Dasha"<<endl;
        else
            cout<<"Masha"<<endl;
    }
}
