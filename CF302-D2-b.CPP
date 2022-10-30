#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, t;
    cin>>n>>t;
    int a, b, arr[n], test[t];
    cin>>a>>b;
    arr[0]=a*b;
    for(int i=1; i<n; i++)
    {
        cin>>a>>b;
        arr[i]=arr[i-1]+a*b;
    }
    for(int i=0; i<t; i++)
    {
        cin>>test[i];

    }
    a=arr[0];
    int j=0;
    for(int i=0; i<t; i++)
    {
        b=test[i];
        if(a>=b)
        {
            cout<<j+1<<endl;
        }
        else
        {
            j++;
            a=arr[j];
            i--;
        }
    }
}
