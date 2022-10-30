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
        int arr[n], ar[n], ch=0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            ar[i]=arr[i];
        }
        sort(ar, ar+n);
        for(int i=0; i<n; i++)
        {
            if(ar[i]!=arr[i])
            {
                if(ar[i]%ar[0]!=0)
                {
                    ch=-1;
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        if(!ch)
        {
            cout<<"YES"<<endl;
        }
    }
}
