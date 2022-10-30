#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    int a=max(n,m);
    int cost=0,arr[a], j=0;

    for(int i=n; i>=0; i--)
    {
        arr[i]=j;
        j++;
    }
    if(m<n)
        cout<<arr[m]<<endl;
    else
    {
        while(m>n)
        {
            cost+=(m%2);
            m=(1+m)/2;
            cost++;
        }

        cost+=arr[m];
        cout<<cost<<endl;
    }

}
