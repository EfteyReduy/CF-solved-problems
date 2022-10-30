#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, a;
    cin>>n>>m;
    //cin>>a;
    long long x=n+1;
    x=x/2;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n%2)
    {
        if(m<x)
        {
            cout<<m+1<<endl;
        }
        else{
            cout<<m-1<<endl;
        }
    }
    else{
        if(m<=x)
        {
            cout<<m+1<<endl;
        }
        else{
            cout<<m-1<<endl;
        }
    }
}
