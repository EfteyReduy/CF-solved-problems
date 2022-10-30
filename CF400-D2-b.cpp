#include<bits/stdc++.h>
using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n; i++)
    {
        cin>>s[i];
    }
    int S, G, ans=0;
    set<int>st;
    bool t=true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='S')
                S=j;
            if(s[i][j]=='G')
                G=j;
        }
        int a=S-G-1;
        if(a>=0)
        {
            st.insert(a);
        }
        else{
            t=false;
            break;
        }
    }
    if(t)
    {
        cout<<st.size()<<endl;
    }else{
        cout<<-1<<endl;
    }
}
