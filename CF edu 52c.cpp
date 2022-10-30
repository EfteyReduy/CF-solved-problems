#include<bits/stdc++.h>

using namespace std;

bool desc(const int &a, const int &b)
{
    return a>b;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n, desc);

    int ans=0, temp=0;
    int mm=k;
    for(int i=1; i<n; i++)
    {
        temp=(arr[i-1]-arr[i]);
        for(int j=1; j<=temp; j++)
        {
            if(mm==k and temp>0)
            {
                //cout<<"Here at i = "<<i<<" and arr[i] = "<<arr[i]<<endl;
                ans++;
            }
            if(i>mm)
            {
                j--;
                mm=k;
               // ans++;
            }
            else{
                mm-=i;
            }
        }

    }
    cout<<ans<<endl;
}
