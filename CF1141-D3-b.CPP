#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    vector<int> arr;
    bool c=true;
    int a, mex=0, ans=0, b, j;
    for(int i=0; i<n; i++)
    {
        cin>>j;
        if(j==0)
        {
            if(c)
            {
                a=ans;
                c=false;
            }
            if(ans>mex)
            {
                mex=ans;
            }
            ans=0;
        }
        else if(j==1)
        {
            ans++;
        }
    }
    j=arr.size();
    ans=max(mex,a+ans);

    cout<<ans<<endl;
}
