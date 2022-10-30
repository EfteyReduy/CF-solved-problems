#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        int arr[n];

        set<int>s;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            s.insert(arr[i]);
        }

        float a=s.size();
        float b=k;
        float x=(a/b);
        if(s.size()%k)
            x++;
        int y=x;
        int ans=0;

        if(s.size()>=2 and k==1)
        {
            cout<<-1<<endl;
            continue;
        }else{
            while(1)
            {

                for(int i=0; i<k and s.size(); i++)
                {
                    set<int>::iterator it=s.begin();
                    s.erase(it);
                }
                ans++;
                if(s.size()>0)
                    s.insert(0);
                else
                    break;

            }
        }

        cout<<ans<<endl;

    }
}
//    int n;
//    cin>>n;
//    int arr[n], brr[n], crr[n];
//    for(int i=0; i<n; i++)
//    {
//        cin>>arr[i];
//        //arr[i]=arr[i]%(n+1);
//    }
//    for(int i=0; i<n; i++)
//    {
//        cin>>brr[i];
//        //brr[i]=brr[i]%(n+1);
//    }
//    for(int i=0; i<n; i++){
//        cin>>crr[i];
//        //crr[i]=crr[i]%(n+1);
//    }
//
//    int ans[n]={0};
//    ans[0]=arr[0];
//
//    for(int i=1; i<n; i++)
//    {
//        if(arr[i]==ans[i-1])
//            ans[i]=brr[i];
//        else if(ans[i-1]==brr[i])
//            ans[i]=crr[i];
//        else
//            ans[i]=brr[i];
//    }
//
//    for(int i=0; i<n; i++)
//    {
//        cout<<ans[i]<<" ";
//    }
//    cout<<endl;

