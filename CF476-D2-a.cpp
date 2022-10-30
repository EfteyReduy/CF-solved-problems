#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    if(n<m)
    {
        cout<<-1<<endl;
    }
    else{
        int a=n/2;
        int b=a%m;
        if(b||n%2)b=m-b;
        a=a+b;
        cout<<a<<endl;
    }
}
