#include<bits/stdc++.h>
using namespace std;
bool desc(const int &a, const int &b)
{
    return a>b;
}
main()
{

    int n, k, ans=0;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n,desc);
    set<int> s;
    for(int i=0; i<n; i++)
    {
        int x=s.size(), a=arr[i]+k;
        s.insert(a);
        if(x!=s.size())
        {
            ans++;
            s.erase(a);
            s.insert(arr[i]);
        }
        else{
            s.insert(arr[i]);
        }


    }
    cout<<ans<<endl;

}
