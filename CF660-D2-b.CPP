#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        int i;
        i=a/4;
        if(a%4!=0)
            i++;
        for(int j=0; j<a-i; j++)
        {
            cout<<9;
        }
        while(i--)
            cout<<8;

        cout<<endl;
    }
}
