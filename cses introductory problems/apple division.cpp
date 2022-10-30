#include<bits/stdc++.h>

using namespace std;
long long arr[20], total=0, ans=10000000000;

void cal(int n, int pos, long long sum)
{
    if(pos>=n)
        return;
    ans=min(ans, abs(sum-(total-sum)));

    cal(n, pos+1, sum);
    cal(n, pos+1, sum+arr[pos]);

}



main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        total+=arr[i];
    }
    sort(arr, arr+n, greater<long long >() );
    cal(n, 0, 0);

    cout<<ans<<endl;

}
