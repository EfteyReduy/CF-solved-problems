#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    long long cou=1;
    long long ans=n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<n; i++)
    {
        if(arr[i]==arr[i-1])
        {
            cou++;
        }
        else{
            ans+=(cou*(cou-1))/2;
            cou=1;
        }
    }
    ans+=(cou*(cou-1))/2;
    cout<<ans<<endl;
}
