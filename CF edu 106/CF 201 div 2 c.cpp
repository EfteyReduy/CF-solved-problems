#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    long long arr[n];
    long long g, m=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        m=max(m,arr[i]);
    }
    g=__gcd(arr[0], arr[1]);
    for(int i=2; i<n; i++)
    {
        g=__gcd(g,arr[i]);
    }
    m=m/g;
    m-=n;
    if(m%2)
    {
        cout<<"Alice"<<endl;
    }
    else{
        cout<<"Bob"<<endl;
    }
}
