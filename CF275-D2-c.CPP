#include<bits/stdc++.h>
using namespace std;

main()
{
    long long n, k;
    cin>>n>>k;
    long long arr[n], an=0, ans=0;
    set<long long>s;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++)
    {
        int sz=s.size();
        long long a=arr[i];
        bool b=false;
        if(a%k==0)
        {
            a=a/k;
            b=true;
        }

        s.insert(a);
        if(sz!=s.size())
        {
            an++;
            s.erase(a);
            if(b)
            {

                a=a*k;
                s.insert(a);
            }
            else{
                s.insert(a);
            }
        }
        else{
            ans++;
        }
    }
    ans=max(ans,an);
    cout<<ans<<endl;
}
