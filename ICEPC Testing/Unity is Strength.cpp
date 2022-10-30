#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MAX 100001

lli power(lli base, lli exponent){
    lli result = 1;
    while (exponent != 0) {
        result *= base;
        --exponent;
    }

    return result;
}



int main()
{
    lli t;
    cin>>t;

    while(t--){
        lli n,k;
        cin>>n>>k;

        lli sum = 0;

        for(lli i=0;i<k;i++){
            sum += power(3,i);
        }

        if(sum>=n) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
