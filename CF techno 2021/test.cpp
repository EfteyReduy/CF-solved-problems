#include<bits/stdc++.h>


using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0; i<n-1; i++)
        {
            int idx, m=1000;
            for(int j=i; j<n; j++)
            {
                if(arr[j]<m)
                {
                    m=arr[j];
                    idx=j;
                }
            }


            ans+=(idx-i+1);
            for(int x=i; x<=i+((idx-i)/2); x++)
            {
                swap(arr[x], arr[idx-x+i]);
                //ans++;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}
