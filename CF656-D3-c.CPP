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
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int num=arr[n-1];
        int i=n-1;
        for(i=n-1; i>0; i--)
        {
            if(arr[i]>=arr[i-1]){
                continue;
            }else{
                cout<<"Value of i is: "<<i-1<<endl;
                return 0;
                break;

            }
        }
        int j;
        for(j=0; j<n-1; j++)
        {
            if(arr[j]<=arr[j+1])
            {
                continue;
            }
            else
                break;
        }
        if(i==0)
        {
            cout<<0<<endl;
        }
        else if(j==n-1)
            cout<<0<<endl;
        else
        {
            for(i; i>0; i++){
                if(arr[i]>=arr[i-1])
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            cout<<i+1<<endl;
        }

    }
}
