#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n>>k;
        long long x=n;
        long long mod=1e9+7;
        n=n*(n-1);
        n%=mod;
        long long pp=pow(2,k-1);
        pp--;
        n*=pp;
        n+=x;
        n%=mod;
        cout<<n<<endl;
    }
}
