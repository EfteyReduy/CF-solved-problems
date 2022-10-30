#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n], mex=0;
        for(int i=0;i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]>mex)
                mex=arr[i];
        }
        int a;


        for(int i=0; i<arr[0]; i++)
            cout<<'a';


        if(arr[0]==0)
            cout<<'d';
        cout<<endl;

        bool test=false, ma=true;

        for(int i=0; i<n-1; i++)
        {
            if(arr[i]==0)
                ma=!ma;

            a=arr[i];
            if(arr[i]<arr[i+1])
                a=arr[i+1];

            if(ma)
            {
                for(int j=0; j<a; j++)
                {
                    cout<<'a';
                }
            }
            else if(!ma){
                for(int j=0; j<a; j++)
                {
                    cout<<'z';
                }
            }

            for(int j=a; j<=mex; j++)
            {
                if(i%2==0)
                {
                    cout<<'b';
                    test=!test;
                }
                else
                {
                    cout<<'c';
                }
            }
            cout<<endl;
        }
        if(ma)
            for(int i=0; i<arr[n-1]; i++)
                cout<<'a';
        else
            for(int i=0; i<arr[n-1]; i++)
                cout<<'z';
        if(arr[n-1]==0)
            cout<<'e';
        cout<<endl;
    }
}
