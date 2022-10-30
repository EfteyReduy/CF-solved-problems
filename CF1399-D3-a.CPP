#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int t;
        cin>>t;
        int arr[t];
        for(int i=0; i<t; i++)
        {
            cin>>arr[i];
        }
        bool s=false;
        sort(arr, arr+t);
        for(int i=0; i<t-1; i++)
            if(arr[i+1]-arr[i]>1)
            {
                cout<<"no"<<endl;
                s=true;
                break;
            }

        if(s==false)
            cout<<"yes"<<endl;
    }
}
