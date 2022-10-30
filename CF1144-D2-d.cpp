#include<bits/stdc++.h>
using namespace std;


main()
{
    int n;
    cin>>n;
    int arr[n];
    array<int,200001>cou;
    //memset(cou, 0, sizeof(cou));
    for(int i=0; i<200001; i++)
    {
        cou[i]=0;
    }

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        cou[arr[i]]++;
    }
    int mex=0;
    int mid;
    for(int i=0; i<200001; i++)
    {
        if(cou[i]>mex)
        {
            mex=cou[i];
            mid=i;

        }
    }
    int strt=0;
    for(int i=0;i<n; i++)
    {
        if(arr[i]==mid)
        {
            strt=i;
            break;
        }
    }
    cout<<n-mex<<endl;
    for(int i=strt; i>=0; i--)
    {
        if(arr[i]!=mid)
        {
            if(arr[i]<mid)
            {
                cout<<1<<" "<<i+1<<" "<<i+2<<endl;
            }
            else{
                cout<<2<<" "<<i+1<<" "<<i+2<<endl;
            }
        }
    }

    for(int i=strt; i<n; i++)
    {

        if(arr[i]!=mid)
        {
            if(arr[i]<mid)
            {
                cout<<1<<" "<<i+1<<" "<<i+0<<endl;

            }
            else{
                cout<<2<<" "<<i+1<<" "<<i+0<<endl;
            }
        }
    }

}
