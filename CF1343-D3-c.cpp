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
        int arr[n]={0};
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        long long ans=-1000000001;
        for(int i=0; i<n-1; i++)
        {
            int j=i;
            long long temp=-1000000001;
            bool sign;
            if((arr[j]>0&&arr[j+1]<0)||(arr[j]<0&&arr[j+1]>0))
            {
                sign=true;
                temp=arr[j];
            }
            else
            {
                sign=false;
            }
            while(sign&&j<n-1)
            {
                temp=temp+arr[j+1];
                j++;
                if((arr[j]>0&&arr[j+1]<0)||(arr[j]<0&&arr[j+1]>0))
                {
                    sign=true;
                }
                else
                {
                    sign=false;
                }
            }
            i=j;
            ans=max(ans,temp);

        }

        cout<<ans<<endl;



    }
    return 0;
}
