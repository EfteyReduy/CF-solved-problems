#include<bits/stdc++.h>

using namespace std;

int n;

int power(int m, int e){
    int ans = 1;
    for(int i=1; i<=e; i++)
    {
        ans*=m;
        ans%=n;
    }
    return ans;
}

main()
{
    int p, q;
    cout<<"Enter a prime p = ";
    cin>>p;
    cout<<"Enter another prime q = ";
    cin>>q;

    n = p*q;

    int phi = (p-1)*(q-1);
    int e;
    cout<<"These following values are possible values for e"<<endl;
    for(int i=2; i < phi; i++)
    {
        if(__gcd(phi, i) == 1)
        {
            cout<<i<<" ";
        }
    }
    cout<<"\nEnter value of e : ";
    cin>>e;

    int d;

    for(int i=2; i < phi; i++)
    {
        if(i*e % phi == 1)
        {
            d=i;
            break;
        }
    }
    cout<<"The value of d is : "<<d<<endl;
    int M;
    cout<<"Enter the message number M = ";
    cin>>M;

    int C = power(M, e);

    cout<<"The encrypted message is : "<<C<<endl;

    int D = power(C, d);
    cout<<"The decrypted message is : "<<D<<endl;


}
