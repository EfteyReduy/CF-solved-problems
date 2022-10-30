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
        int arr[n]={0}, mex=-1e9+1, men=1e9+1;
        int mi=men, me=mex;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int i=0, j=n-1, k, ans=0;
        bool it=true, jt=true;
        for(int k=0; k<n; k++)
        {
            if(arr[i]<=arr[i+1]&&it)
            {
                i++;

            }
            else
            {
                int a;
                for(a=i; a<n; a++)
                {
                    if(arr[a]<arr[a+1])
                    {
                        break;
                    }
                }
                int lo=arr[a];
                while(a<n)
                {

                    if(arr[a]>arr[a+1])
                    {
                        break;

                    }
                    a++;
                }
                for(int b=i; b<a; b++)
                {
                    arr[b]=arr[i];
                }

                ans+=(min(arr[i], arr[a])-lo);

            }



        }
        cout<<ans<<endl;
    }

}
