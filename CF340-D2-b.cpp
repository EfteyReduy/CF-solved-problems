#include<bits/stdc++.h>
#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;


main()
{
    int n;
    cin>>n;
    int arr[n], o=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i])o++;
    }
    if(o==0)
    {
        cout<<0<<endl;
        return 0;
    }
    int i, j, k;
    for(i=0; i<n; i++)
    {
        if(arr[i]==1)
            break;
    }
    for(k=n-1; k>=0; k--)
    {
        if(arr[k]==1)
            break;
    }
//    db(i);
//    db(k);

    long long cou=0,ans=1;
    for(j=i; j<k; j++)
    {
        if(arr[j])
        {
            if(cou>0)
            {
                ans*=(cou+1);
            }
            cou=0;
        }
        else{
            cou++;
        }
    }
    ans*=(cou+1);
    cout<<ans<<endl;

}
