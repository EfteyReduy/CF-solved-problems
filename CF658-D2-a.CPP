#include<bits/stdc++.h>
using namespace std;

main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int arr[n], brr[m];
        int ans=0;
        vector<int> c;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        for(int j=0; j<m; j++)
            cin>>brr[j];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i]==brr[j])
                {

                    ans=arr[i];
                    break;
                }
            }
            if(ans>0)
                break;
        }
        if(ans==0)
        {
            cout<<"no"<<endl;

        }
        else{
            cout<<"yes"<<endl;
            cout<<1;
            for(int i=0; i<1; i++)
            {
                cout<<" "<<ans;
            }
            cout<<endl;
        }
    }
}

