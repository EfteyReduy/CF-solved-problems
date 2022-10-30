#include<bits/stdc++.h>

#define db(x) cout<<#x<<" = "<<x<<endl

using namespace std;

vector<long long> arr;

long long ans=0, n, l, r, x;

void comple(long long low, long long hi, long long sum, long long pos)
{
    if(pos>=n)
        return;


    comple(low, hi, sum, pos+1);

    low=min(low, arr[pos]);
    hi=max(hi, arr[pos]);
    sum+=arr[pos];


    comple(low, hi, sum, pos+1);
    if(sum>=l and sum<=r)
    {
        if(hi-low>=x)
            ans++;
    }


}


main()
{

    cin>>n>>l>>r>>x;


    for(int i=0; i<n; i++)
    {
        long long a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin() ,arr.end() );

    int i=0, j=0;

    comple(1000000002, 0, 0, 0);
    cout<<ans<<endl;

}
