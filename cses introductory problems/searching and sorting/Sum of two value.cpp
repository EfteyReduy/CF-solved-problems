#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, s;
    cin>>n>>s;
    pair<long long, long long> arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr, arr+n);

    for(int i=0; i<n; i++)
    {
        long long x=s-arr[i].first;
        pair<long long, long long> p={x+1, 0};

        auto it=lower_bound(arr, arr+n, p);
        if(it==arr)
            continue;
        it--;
        p=*it;
        if(x==p.first and p.second!=arr[i].second)
        {
            cout<<p.second<<" "<<(arr[i].second)<<endl;
            return 0;
        }


    }

    cout<<"IMPOSSIBLE"<<endl;
}
