#include<bits/stdc++.h>
using namespace std;

main()
{

    int n;
    cin>>n;
    int ans=(n*(n+1))/2;
    if(n==1)
    {
        cout<<"YES"<<endl;
    }
    else if(ans%n==0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }

}
