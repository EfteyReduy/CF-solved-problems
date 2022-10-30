#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    for(int cc=1; cc<=t; cc++)
    {
        string num;
        cin>>num;
        int n=num.length();
        int arr[n];
        long long total=0;
        for(int i=0; i<n; i++)
        {
            arr[i]=num[i]-'0';
            total+=arr[i];
        }
        total%=9;

        cout<<"Case #"<<cc<<": ";
        bool found = false;
        for(int i=0; i<n; i++)
        {
            if(arr[i]<found and !found)
            {
                cout<<9-total;
                found = true;
            }
            cout<<arr[i];
        }
        if(!found)
        {
            cout<<9-total;
        }
        cout<<endl;
    }
}

