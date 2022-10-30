#include<bits/stdc++.h>

using namespace std;

main()
{
    long long i, n, ans=0;
    cin>>i;
    for(n=1; n<=i; n++)
        cout<<((n - 1)*(n + 4)*(n*n - 3*n + 4)/2)<<endl;

}
