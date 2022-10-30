#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(1)
    {
        int arr[t];
        for(int i=0; i<t; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+t);
        int x=arr[t-1], y=1;

        vector<int>v;
        y=sqrt(x);
        for(int i=1; i<=y; i++)
        {
            if(x%i==0)
            {
                v.push_back(i);
                if(x/i!=i)
                    v.push_back(x/i);
            }
        }
        for(int i=0; i<v.size(); i++)
        {
            int a=v[i];
            for(int j=0; j<t; j++)
            {
                if(arr[j]==a)
                {
                    arr[j]=0;
                    break;
                }
            }

        }
        sort(arr, arr+t);
        y=arr[t-1];



        cout<<x<<" "<<y<<endl;
        return 0;
    }
}
