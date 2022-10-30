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

        int ans=0, cou=1, temp=0;
        for(int i=1; i<n; i++)
        {
            if(arr[i]>arr[i-1])
            {
                ans++;
                temp++;
                if(i==1)
                    ans--,temp--;
            }
            else{
                ans--;
                if(ans<0)
                {
                    ans=0;
                    cou++;
                    temp--;
                    ans=temp;
                }
            }
        }
        cout<<cou<<endl;
    }
}
