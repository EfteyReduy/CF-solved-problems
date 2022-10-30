#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],ans=1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0; arr[i]==1 && i<n-1;i++)
        {
            ans = ans * (-1);
        }
        if(ans == 1)
            cout<<"First\n";
        else
            cout<<"Second\n";
    }
    return 0;
}
