#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, ans=0, cou=0;
    cin>>n;
    while(n>0){
        n=n/5;
        ans+=(n);
    }
    cout<<ans<<endl;
}
