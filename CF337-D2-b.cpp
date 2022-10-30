#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long n;
    cin>>n;
    long long arr[n], low=1e9, idx=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]<low)
            low=arr[i], idx=i;
    }

    long long ans=(low*n);
    long long i, j, k;
    vector<long long>temp;
    for(i=0; i<n; i++)
    {
        if(arr[i]==low)
            temp.push_back(i);
    }
    j=temp.size();
    k=max(temp[0]-temp[j-1], n-temp[j-1]-1+temp[0]);

    for(i=0; i<j-1; i++)
    {
        k=max(k, temp[i+1]-temp[i]-1);
    }
    ans+=k;
    cout<<ans<<endl;

}
