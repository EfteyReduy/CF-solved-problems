#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    int arr[m]={0};
    for(int i=0; i<n; i++)
    {
        int a=0;
        cin>>a;
        a=a%m;
        arr[a]++;

    }

//    for(int i=0; i<m; i++)
//    {
//        cout<<arr[i]<<endl;
//
//    }return 0;
    int ans=0;
    for(int i=1; i<=m/2; i++)
    {
        int a=min(arr[i],arr[m-i]);
        if(i==(m/2)&&m%2==0)
        {
            //cout<<"here"<<endl;
            if(a%2!=0)
                a--;
            ans+=a;
        }
        else
            ans+=(a*2);
        //cout<<a<<endl;
    }
    arr[0]=arr[0]/2;
    arr[0]=arr[0]*2;
    ans=ans+arr[0];
    cout<<ans<<endl;

}
