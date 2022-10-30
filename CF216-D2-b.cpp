#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, k, l, r, sa, sk;
    cin>>n>>k>>l>>r>>sa>>sk;
    vector<int> ans;

    int x=sk/k, y=sk%k;

    for(int i=0; i<k; i++)
    {
        int a=x;
        if(y)
        {
            a+=1;
            y--;
        }
        ans.push_back(a);
    }
    k=n-k;
    sk=sa-sk;

    if(k>0)x=sk/k, y=sk%k;
    for(int i=0; i<k; i++)
    {
        int a=x;
        if(y)
        {
            a+=1;
            y--;
        }
        ans.push_back(a);
    }

    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;



}
