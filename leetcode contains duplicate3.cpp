#include<bits/stdc++.h>

using namespace std;


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<int>st;
    int nums[4]={1, 2, 3, 1};
    int k=sizeof(nums)/4;
    cout<<k<<endl;
    for(int i=0; i<k; i++)
    {
        cout<<i<<endl;
        auto x=st.lower_bound(nums[i]);
        if(x!=st.end()){
            int a = *x;
            cout<<nums[i]<<"  "<<*x<<endl;
        }
        st.insert(nums[i]);
    }
}
