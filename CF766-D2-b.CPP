#include<bits/stdc++.h>
using namespace std;


bool desc(const int &a, const int &b)
{
    return a>b;
}

main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i <n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n, desc);
    int a=arr[0];
    bool b=false;
    for(int i=0; i<n-2; i++)
    {
        if(arr[i]<arr[i+1]+arr[i+2]){
            cout<<"YES"<<endl;
            b=true;
            break;
        }
    }
    if(!b)
        cout<<"NO"<<endl;

}
