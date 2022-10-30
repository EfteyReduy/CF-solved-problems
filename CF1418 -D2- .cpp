#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long  x, y, k;
        int n;
        cin>>n;
        int arr[n];
        bool pos[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n ; i++)
        {
            cin>>pos[i];
        }
        vector<int> fix, flex;
        for(int i=0; i<n; i++)
        {
            if(pos[i])
            {
                fix.push_back(arr[i]);

            }
            else{
                flex.push_back(arr[i]);
            }
        }
        sort(flex.begin(), flex.end(), greater<int>());
        int j=0;
        for(int i=0; i<n ; i++)
        {
            if(!pos[i])
            {
                arr[i]=flex[j];
                j++;
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
}


/*
5
2 1 5
42 13 24
12 11 12
1000000000 1000000000 1000000000
2 1000000000 1000000000
*/
