
#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    vector<pair<int, int> > asc, des;

    for(int i=0; i<m; i++)
    {
        int t, l, r;
        cin>>t>>l>>r;
        if(t==1)
            asc.push_back(make_pair(l,r));
        else
            des.push_back(make_pair(l,r));
    }
    int arr[n]={0};
    for(int i=0; i<asc.size(); i++)
    {
        int a=asc[i].first;
        int b=asc[i].second;
        for(int j=a-1; j<b-1; j++)
        {
            arr[j]=1;
        }
    }
    bool f=true;
    bool x=true;
    for(int i=0; i<des.size(); i++)
    {
        int a=des[i].first;
        int b=des[i].second;
        x=true;
        for(int j=a-1; j<b-1; j++)
        {

            if(arr[j]==1)
            {

                continue;
            }
            else
            {
                f=false;
                arr[j]=2+x;
                break;

            }

        }
        if(f==false)
        {
            continue;
        }
        else{
            break;
        }

    }
    arr[n-1]=1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0){
            arr[i]=2+x;
            x=!x;
        }
    }
    if(!f)
    {
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }



}
