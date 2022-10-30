#include<bits/stdc++.h>
using namespace std;


main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<n; i++)
    {
        if(arr[i]==3)
        {
            if(arr[i-1]==0)
            {
                int j=i;
                while(arr[j]==3)
                {
                    j++;
                }

                if(1)
                {
                    int k=j;
                    for( ; k>i; k--)
                    {
                        if(arr[k]==2)
                            arr[k-1]=1;
                        else //(arr[k]==1)
                            arr[k-1]=2;

                    }
                }

            }
            else{
                if(arr[i-1]==1)
                    arr[i]=2;
                else if(arr[i-1]==2)
                    arr[i]=1;
            }
        }

        if(arr[i]==arr[i-1] and arr[i]!=3)
            arr[i]=0;

    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
            ans++;
    }

    cout<<ans<<endl;


}

/**
100
3 2 3 3 3 2 3 1 3 2 2 3 2 3 3 3 3 3 3 1 2 2 3 1 3 3 2 2 2 3 1 0 3 3 3 2 3 3 1 1 3 1 3 3 3 1 3 1 3 0 1 3 2 3 2 1 1 3 2 3 3 3 2 3 1 3 3 3 3 2 2 2 1 3 1 3 3 3 3 1 3 2 3 3 0 3 3 3 3 3 1 0 2 1 3 3 0 2 3 3

3 2 1 2 1 2 1 1 2 2 2 1 2 1 2 1 2 1 2 1 2 2 1 1 2 1 2 2 2 1 1 0 1 2 1 2 1 2 1 1 2 1 2 1 2 1 2 1 2 0 1 2 2 1 2 1 1 2 2 1 2 1 2 1 1 2 1 2 1 2 2 2 1 2 1 2 1 2 1 1 2 2 1 2 0 2 1 2 1 2 1 0 2 1 2 1 0 2 1 2

**/

