#include<bits/stdc++.h>
using namespace std;


main(){
    long long a, b, c;
    cin>>a>>b>>c;
    if(a==b and b==c)
    {
        cout<<"Equilateral Triangle"<<endl;
    }
    else if(a==b or b==c or a==c)
    {
        cout<<"Isosceles Triangle"<<endl;
    }
    else{
        cout<<"Bad Triangle"<<endl;
    }
}
