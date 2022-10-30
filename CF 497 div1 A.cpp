#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int men=1000000000;
    map<int, int>mp;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        if(arr[i]<men)
        {
            men=arr[i];
        }
    }
    sort(arr, arr+n);
    int ans=0, rem=0;
    for(auto it:mp)
    {
        if(rem==0)
        {
            rem=it.second;
        }
        else{
            ans+=(min(rem,it.second));
            rem=max(rem, it.second);
        }
    }
    cout<<ans<<endl;
}
