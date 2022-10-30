#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll l, r;
        cin>>l>>r;
        ll ans=1;
        ll mod= 1e12;

        bool neg=false;
        if(l<0)
        {
            neg=true;
        }

        for(ll i=min(abs(l), abs(r)); i<=max(abs(r), abs(l)); i++)
        {
            ans*=i;
            while(ans>mod)
            {
                ans/=10;
            }
        }

        while(ans>1e5)
        {
            ans/=10;
        }

        if(neg)
        {
            if((l-r)%2)
            {
                ans=-ans;
            }
        }

        cout<<ans<<endl;

    }
    return 0;
}
