#include<bits/stdc++.h>
#define ll long long
using namespace std;

main()
{
    ll n;
    cin>>n;
    ll arr[n], sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    if(sum%3)
    {
        cout<<0<<endl;
        return 0;
    }

    ll temp=sum/3;
    bool f1=false, f2=false;
    ll i, t1=0, t2=0;
    for(i=0; i<n; i++)
    {
        t1+=arr[i];
        if(t1==temp)
        {
            f1=true;
            break;
        }
    }

    int j=0,cou=0;
    for( j=n-1; i<j; j--)
    {
        t2+=arr[j];
        if(t2==temp)
        {
            f2=true;
            break;
        }
    }

    if(f1 and f2)
    {
        ll cum=0, ans=0;
        for(i=0; i<n-1; i++)
        {
            cum+=arr[i];
            if(cum==2*temp)
            {
                ans+=cou;
            }
            if(cum==temp)
            {
                cou++;
            }
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }

}
