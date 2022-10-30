#include<bits/stdc++.h>
using namespace std;

main()
{
    int n, k;
    cin>>n>>k;
    for(int i=0; i<k; i++)
    {
        cout<<2*i+2<<" "<<2*i+1<<" ";
    }
    for(int i=k; i<n; i++)
    {
        cout<<2*i+1<<" "<<2*i+2;
        if(i!=n-1)
        {
            cout<<" ";
        }
    }

}
