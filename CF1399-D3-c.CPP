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
        int arr[n], i, j, ans=0, temp=0, k;
        bool block[n]={0};

        for(i=0; i<n; i++)
        {
            cin>>arr[i];
        }
       // sort(arr, arr+n);

        for(i=2; i<=n*2; i++)
        {
            for(j=0;j<n; j++)
            {


                for(k=j+1; k<n; k++)
                {

                    if(arr[j]+arr[k]==i&&block[j]==0&&block[k]==0){
                        temp++;
                        block[j]=1;
                        block[k]=1;
                        break;

                    }

                }
            }
            ans=max(ans,temp);
            temp=0;
            for(int a=0; a<n; a++)
                block[a]=0;
        }
        cout<<ans<<endl;
    }
}
