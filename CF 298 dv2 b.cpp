#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, t, d, ans=0;
    cin>>a>>b>>t>>d;

    for(int i=0; i<t; i++)
    {
        if(a>b)
            swap(a,b);
        ans+=a;
        a+=d;
    }
    cout<<ans<<endl;

}
