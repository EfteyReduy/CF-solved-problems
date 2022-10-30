#include<bits/stdc++.h>


using namespace std;

main()
{
    int n, k, j;
    cin>>n>>k;
    set<int> st;
    vector<int>v;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        j=st.size();
        st.insert(a);

        if(st.size()>j)
        {
            v.push_back(i);
        }

    }
    if(v.size()<k)
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0; i<k; i++)
        {
            cout<<v[i]+1<<" ";
        }
        cout<<endl;
    }
}
