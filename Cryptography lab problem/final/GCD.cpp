#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    else{
        return gcd(b, a%b);
    }
}
main()
{
    int a, b;
    cout<<"Enter the first number : ";
    cin>>a;
    cout<<"Enter the second number : ";
    cin>>b;
    cout<<"GCD of a and b is: "<<gcd(a, b)<<endl;
}
