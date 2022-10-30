
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int arr[2*n]={};
        int m=2*n;
        while(m--){
            int a;
            cin>>a;
            if(arr[a]==0){
                cout<<a<<" ";
                arr[a]=1;
            }
        }
        cout<<endl;
    }
    return 0;
}
