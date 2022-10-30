#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long ans=0, n, tot;
    cin>>n;
    tot=n*(n+1)/2;
    int arr[n];
    vector<int>neg;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]<0)
        {
            neg.push_back(1+i);
        }
    }

    int x=neg.size();
    if(x==0)
    {
        cout<<0<<" "<<n*(n+1)/2<<endl;
        return 0;
    }
    else if(x==1)
    {
       // cout<<"HERE"<<endl;
        ans=(neg[0])*(n-neg[0]+1);
        cout<<ans<<" "<<tot-ans<<endl;
        return 0;
    }
    long long cum[neg.size()];

    cum[x-1]=n-neg[x-1]+1;
    cum[x-2]=neg[x-1]-neg[x-2];
    for(int i=x-3; i>=0; i--)
    {
        cum[i]=neg[i+1]-neg[i]+cum[i+2];
    }
    ans=neg[0]*cum[0];
    for(int i=1; i<x; i++)
    {
        ans+=(cum[i]*(neg[i]-neg[i-1]));
    }
    cout<<ans<<" "<<tot-ans<<endl;
}
